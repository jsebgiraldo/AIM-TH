#include "aim.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_err.h"

#include "ui_wifi_screen.h"

#include "wifi_app.h"
#include "app_smb.h"

#include "event_router.h"

static QueueHandle_t mediator_queue;

static const char *state_name[STATE_LAST] = 
{
    "STATE_INVALID",
    "STATE_WIFI_CONFIG", 
    "STATE_MAIN_SCREEN", 
    "STATE_SHARED_FOLDER", 
};


#define WATER_DIS_DEBUG_ENABLE
#ifndef WATER_DIS_DEBUG_ENABLE
	#define WATER_DIS_DEBUG(...)
#else
// Tag used for ESP serial console messages
	static const char *TAG = "[WATER DISPENSER]";
	#define WATER_DIS_LOGI(...) ESP_LOGI(TAG, LOG_COLOR(LOG_COLOR_BLUE) __VA_ARGS__)
	#define WATER_DIS_LOGE(...) ESP_LOGE(TAG, LOG_COLOR(LOG_COLOR_BLUE) __VA_ARGS__)
	#define WATER_DIS_LOGW(...) ESP_LOGW(TAG, LOG_COLOR(LOG_COLOR_BLUE) __VA_ARGS__)
#endif


#define aim_device_QUEUE_ITEMS       (10)

//******************** FUNCTION DEFINITION *****************************************//

static void aim_device_set_state(aim_device_fsm_t *fsm, aim_device_state_t state);

static void main_screen_enter_seq(aim_device_fsm_t *fsm);
static void main_screen_entry_action(aim_device_fsm_t *fsm);
static esp_err_t on_state_main_screen(aim_device_fsm_t *fsm);

static void wifi_config_enter_seq(aim_device_fsm_t *fsm);
static void wifi_config_entry_action(aim_device_fsm_t *fsm);
static esp_err_t on_state_wifi_config(aim_device_fsm_t *fsm);

static void shared_folder_enter_seq(aim_device_fsm_t *fsm);
static void shared_folder_entry_action(aim_device_fsm_t *fsm);
static esp_err_t on_state_shared_folder(aim_device_fsm_t *fsm);


//****************************** MAIN MENU *****************************************//

static void main_screen_enter_seq(aim_device_fsm_t *fsm)
{
    aim_device_set_state(fsm, STATE_MAIN_SCREEN);
    WATER_DIS_LOGI("enter seq -> [%s]", state_name[fsm->state]);
    main_screen_entry_action(fsm);
}

static void main_screen_entry_action(aim_device_fsm_t *fsm)
{
    WATER_DIS_LOGI("entry action -> [%s]", state_name[fsm->state]);

    event_t event_out = {
        .src = TASK_AIM,
        .dest = TASK_UI,
        .id = EVT_UI_SHOW_MAIN_SCREEN, };
    event_router_write(&event_out);
}

static esp_err_t on_state_main_screen(aim_device_fsm_t *fsm)
{
    switch (fsm->event.id)
    {

    case EVT_BUTTON_1_PRESSED: 
    case EVT_UI_WIFI_SELECTED: 
    {
        wifi_config_enter_seq(fsm);
    } break;

    case EVT_BUTTON_2_PRESSED:
    case EVT_UI_SHARED_FOLDER_SELECTED: {
        shared_folder_enter_seq(fsm);
    } break;

    case EVT_BUTTON_3_PRESSED: {
    } break;

    case EVT_BUTTON_4_PRESSED: {
    } break;
    

    default:
        WATER_DIS_LOGW("event [%s] not handled in state [%s]",
                       event_router_get_id_name(fsm->event.id),
                       state_name[fsm->state]);
        break;
    }

    return ESP_OK;
}

//****************************** DEV CONFIG  ********************************************//

static void wifi_config_enter_seq(aim_device_fsm_t *fsm)
{
    aim_device_set_state(fsm, STATE_WIFI_CONFIG);
    WATER_DIS_LOGI("enter seq -> [%s]", state_name[fsm->state]);
    wifi_config_entry_action(fsm);
}

static void wifi_config_entry_action(aim_device_fsm_t *fsm)
{
    WATER_DIS_LOGI("entry action -> [%s]", state_name[fsm->state]);

    event_t event_out = {
        .src = TASK_AIM,
        .dest = TASK_UI,
        .id = EVT_UI_SHOW_WIFI_SCREEN, };
    event_router_write(&event_out);
}


static esp_err_t on_state_wifi_config(aim_device_fsm_t *fsm)
{
    switch (fsm->event.id)
    {

    case EVT_BUTTON_1_PRESSED:
    case EVT_UI_HOME_SELECTED: 
     {
        main_screen_enter_seq(fsm);
    } break;

    case EVT_BUTTON_2_PRESSED: {
    } break;

    case EVT_BUTTON_3_PRESSED: {
    } break;

    case EVT_BUTTON_4_PRESSED: {
    } break;
    
    case EVT_UI_SCAN_BTN_CLICKED: 
    {
        
        WATER_DIS_LOGI("Starting Scanning\r\n");
        vTaskDelay(100/portTICK_PERIOD_MS);

        ui_set_status_msg("Scanning Networks...");
        ui_show_scanning_panel();
        
        esp_wifi_scan_start(NULL, true);
        uint16_t ap_count = 0;
        esp_wifi_scan_get_ap_num(&ap_count);
        printf("Number of WiFi networks found: %d\n", ap_count);
        wifi_ap_record_t *ap_list = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t) * ap_count);
        esp_wifi_scan_get_ap_records(&ap_count, ap_list);

        char ap_list_view[ap_count *MAX_SSID_LEN];
        memset(ap_list_view,0,sizeof(ap_list_view));

        for (int i = 0; i < ap_count; i++) {
            strcat(ap_list_view,(char *)ap_list[i].ssid);
            strcat(ap_list_view,"\n");
            printf("SSID: %s, RSSI: %d\n", ap_list[i].ssid, ap_list[i].rssi);
        }

        free(ap_list);

        ui_set_status_msg("Scanning Complete!");
        ui_show_networks_panel();
        ui_set_scanned_networks(ap_list_view);
    }
    break;

    case EVT_UI_CONNECT_BTN_CLICKED: 
    {
        WATER_DIS_LOGI("Connecting WiFi....\r\n");

        ui_set_status_msg("Attempt to connect ...");

        char *ssid_str = ui_get_network_ssid();
        char *pass_str = ui_get_network_password();

        WATER_DIS_LOGI("Network Selected [%s]", ssid_str);
        WATER_DIS_LOGI("Password [%s]", pass_str);

        wifi_config_t* wifi_config = wifi_app_get_wifi_config();

        memset(wifi_config,0x00,sizeof(wifi_config_t));
        memcpy(wifi_config->sta.ssid, ssid_str, strlen(ssid_str));
	    memcpy(wifi_config->sta.password, pass_str, strlen(pass_str));
        wifi_app_send_message(WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER);

        ui_show_connecting_panel_in_progress();
    } break;

    case EVT_UI_WIFI_CONN_SUCCEED:
    {
        ui_set_status_msg("Connection succeed ");
        ui_show_connecting_panel_succeed();
    }break;

    case EVT_UI_WIFI_CONN_FAIL:
    {
        ui_set_status_msg("Connection Failed ");
        ui_show_connecting_panel_fail();
        vTaskDelay(2500/portTICK_PERIOD_MS);

        ui_show_password_panel();
    }break;

    default:
        WATER_DIS_LOGW("event [%s] not handled in state [%s]",
                       event_router_get_id_name(fsm->event.id),
                       state_name[fsm->state]);
        break;
    }

    return ESP_OK;
}


//****************************** SHARED FOLDER  ********************************************//

static void shared_folder_enter_seq(aim_device_fsm_t *fsm)
{
    aim_device_set_state(fsm, STATE_SHARED_FOLDER);
    WATER_DIS_LOGI("enter seq -> [%s]", state_name[fsm->state]);
    shared_folder_entry_action(fsm);
}

static void shared_folder_entry_action(aim_device_fsm_t *fsm)
{
    WATER_DIS_LOGI("entry action -> [%s]", state_name[fsm->state]);

    event_t event_out = {
        .src = TASK_AIM,
        .dest = TASK_UI,
        .id = EVT_UI_SHOW_FOLDER_SCREEN, };
    event_router_write(&event_out);
}


static esp_err_t on_state_shared_folder(aim_device_fsm_t *fsm)
{
    switch (fsm->event.id)
    {

    case EVT_BUTTON_1_PRESSED:  {
    } break;

    case EVT_BUTTON_2_PRESSED:
    case EVT_UI_HOME_SELECTED: {
        main_screen_enter_seq(fsm);
    } break;

    case EVT_UI_LS_BTN_CLICKED: {

        ui_set_status_msg("Share Folder Found!!");

        app_smb_set_user("User31");
        app_smb_set_password("123push");
        char *path_str = "Share_network";

        ui_share_folder_set_content((char *)app_smb_ls(path_str));

        char LabelNetworkInfo_str[30];
        tcpip_adapter_ip_info_t ip_info;
        tcpip_adapter_get_ip_info(TCPIP_ADAPTER_IF_STA, &ip_info);

        smb_config_t *smb_config = app_smb_get_config();

        sprintf(LabelNetworkInfo_str,"smb://%s@%s/%s",smb_config->user,ip4addr_ntoa(&ip_info.gw),path_str);
        ui_share_folder_set_sbm_name(LabelNetworkInfo_str);

    } break;

    default:
        WATER_DIS_LOGW("event [%s] not handled in state [%s]",
                       event_router_get_id_name(fsm->event.id),
                       state_name[fsm->state]);
        break;
    }

    return ESP_OK;
}


//***************************************** END *****************************************//

static void aim_device_set_state(aim_device_fsm_t *fsm, aim_device_state_t state)
{
    fsm->state = state;
    memset(&fsm->event, 0, sizeof(event_t));
    WATER_DIS_LOGI("new state -> [%s]", state_name[state]);
}


esp_err_t aim_device_write_event(event_t *event)
{
    if (xQueueSend(mediator_queue, event, (TickType_t)10) == pdPASS) {
        return ESP_OK;
    }
    else {
        WATER_DIS_LOGE("Event Lost !!! -> [%d]\r\n", event->id);
        return ESP_FAIL;
    }
}

static esp_err_t aim_device_read_event(aim_device_fsm_t *fsm)
{
    if (xQueueReceive(mediator_queue, &fsm->event, portMAX_DELAY) == pdPASS)
    {
        return ESP_OK;
    }
    return ESP_FAIL;
}


static esp_err_t aim_device_process_event(aim_device_fsm_t *fsm)
{
    switch (fsm->state)
    {
        case STATE_WIFI_CONFIG:    on_state_wifi_config(fsm);     break; 
        case STATE_MAIN_SCREEN:    on_state_main_screen(fsm);     break;
        case STATE_SHARED_FOLDER:  on_state_shared_folder(fsm);   break;
    default:
        break;
    }
    
    return ESP_OK;
}

static void aim_device_fsm_init(aim_device_fsm_t *fsm)
{
    main_screen_enter_seq(fsm);
}


void aim_device_task(void* arg)
{
    aim_device_fsm_t fsm;
    aim_device_fsm_init(&fsm);

    while (1)
    {
        if(aim_device_read_event(&fsm) == ESP_OK)
        {
            aim_device_process_event(&fsm);
        }  
    }
}


void aim_device_init(void)
{
    mediator_queue = xQueueCreate(aim_device_QUEUE_ITEMS , EVENT_ITEM_SIZE_BYTES);
    xTaskCreate(aim_device_task, "aim_task", 1024*6, NULL, 10, NULL);

    WATER_DIS_LOGI("Water Dispenser initialized");
}

