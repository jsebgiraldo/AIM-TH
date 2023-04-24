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


#include "event_router.h"

static QueueHandle_t mediator_queue;

static const char *state_name[STATE_LAST] = 
{
    "STATE_INVALID",
    "STATE_WIFI_CONFIG", 
    "STATE_MAIN_SCREEN", 
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

    case EVT_BUTTON_2_PRESSED: // Wash
    case EVT_BUTTON_3_PRESSED: // Fill
    case EVT_BUTTON_4_PRESSED: // Reset
    {
        // event_t event_out = {
        //     .src = TASK_AIM,
        //     .dest = TASK_UI,
        //     .id = EVT_UI_SHOW_RATES_SCREEN,
        // };
        // event_router_write(&event_out);
    }
    break;
    
    case EVT_BUTTON_1_PRESSED: // Config Button
    {
        wifi_config_enter_seq(fsm);
    }
    break;

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
    case EVT_WIFI_STA_CONNECTED:
    {
        // event_t event_out = {
        //     .src = TASK_AIM,
        //     .dest = TASK_UI,
        //     .id = EVT_UI_SHOW_WIFI_CONFIG_MENU_2,
        // };
        // event_router_write(&event_out);
    }
    break;

    case EVT_WIFI_GOT_IP:
    {
        // event_t event_out = {
        //     .src = TASK_AIM,
        //     .dest = TASK_UI,
        //     .id = EVT_UI_SHOW_WIFI_CONFIG_MENU_4,
        // };
        // event_router_write(&event_out);
    }
    break;

    case EVT_HTTP_CLIENT_CONNECTED:
    {
        // event_t event_out = {
        //     .src = TASK_AIM,
        //     .dest = TASK_UI,
        //     .id = EVT_UI_SHOW_WIFI_CONFIG_MENU_3,
        // };
        // event_router_write(&event_out);
    }
    break;

    case EVT_WIFI_STA_DISCONNECTED:
    case EVT_BUTTON_1_PRESSED: 
    {
        main_screen_enter_seq(fsm);
    }
    break;

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
        case STATE_MAIN_SCREEN:    on_state_main_screen(fsm);    break;
    
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
    xTaskCreate(aim_device_task, "water_task", 2048*2, NULL, 10, NULL);

    WATER_DIS_LOGI("Water Dispenser initialized");
}

