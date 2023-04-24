
#include "event_router.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_err.h"
#include "string.h"

// task includes 
#include "ui.h"
#include "aim.h"

#define EVT_ROUTER_DEBUG_ENABLE
#ifndef EVT_ROUTER_DEBUG_ENABLE
	#define EVT_ROUTER_DEBUG(...)
#else
// Tag used for ESP serial console messages
	static const char *TAG = "[EVT ROUTER]";
	#define EVT_ROUTER_LOGI(...) ESP_LOGI(TAG, LOG_COLOR(LOG_COLOR_CYAN) __VA_ARGS__)
	#define EVT_ROUTER_LOGE(...) ESP_LOGE(TAG, LOG_COLOR(LOG_COLOR_CYAN) __VA_ARGS__)
	#define EVT_ROUTER_LOGW(...) ESP_LOGW(TAG, LOG_COLOR(LOG_COLOR_CYAN) __VA_ARGS__)
#endif

static QueueHandle_t event_queue;
static TaskHandle_t  event_router_handle;


const char *task_id_name[TASK_LAST] = 
{
    "TASK_INVALID",
    "TASK_AIM",
    "TASK_UI",
    "TASK_BUTTONS",
    "TASK_WIFI",
    "TASK_HTTP",
};

const char *event_id_name[] = 
{
    "EVT_INVALID",
    BTN_EVENTS_NAME,
    UI_EVENTS_NAME,
    WIFI_EVENTS_NAME, 
    HTTP_EVENTS_NAME
};

#define MAX_QUEUE_ITEMS           (10)
#define MAX_QUEUE_SEND_TIMEOUT_MS (5)

char *event_router_get_id_name(event_id_t id)
{
    return (char *)event_id_name[id];
}

char *event_router_get_task_name(task_id_t id)
{
    return (char *)task_id_name[id];
}

void event_router(void *args);

void event_router_init(void)
{
    EVT_ROUTER_LOGI("Initializing Event Router...");
    event_queue = xQueueCreate(MAX_QUEUE_ITEMS, EVENT_ITEM_SIZE_BYTES);
    xTaskCreate(event_router, "event_router", 4096, NULL, 11, &event_router_handle);
}

esp_err_t event_router_write(event_t *event)
{
    if (xQueueSend(event_queue, event, pdMS_TO_TICKS(MAX_QUEUE_SEND_TIMEOUT_MS)) == pdPASS)
    {
        return ESP_OK;
    }
    else
    {
        EVT_ROUTER_LOGE("Event Lost !!! -> [%d]\r\n", event->id);
        return ESP_FAIL;
    }
}

static void print_event_info(event_t *event)
{
    EVT_ROUTER_LOGI("\tsrc     = \t[%s]\n\t \
                     \tdest    = \t[%s]\n\t \
                     \tevt id  = \t[%s]\n\t \
                     \tevt len = \t[%d]",
                    task_id_name[event->src], task_id_name[event->dest],
                    event_id_name[event->id], event->payload.len);
}

esp_err_t event_route_read(event_t *event)
{
    if (xQueueReceive(event_queue, event, portMAX_DELAY) == pdPASS)
    {
        if (IS_VALID_TASK_ID(event->src) && IS_VALID_TASK_ID(event->dest))
        {
            print_event_info(event);
            return ESP_OK;
        }
        else
        {
            EVT_ROUTER_LOGE("Destination or Source Invalid -> [%d][%d]", event->src, event->dest);
            return ESP_FAIL;
        }
    }
    return ESP_FAIL;
}

void event_router(void *args)
{
    event_t event;
    while (1)
    {
        if (event_route_read(&event) == ESP_OK)
        {
            switch (event.dest)
            {
            case TASK_AIM:
                aim_device_write_event(&event);
                break;
            case TASK_UI:
                ui_write_event(&event);
                break;
            default:
                EVT_ROUTER_LOGW("Task id not handled-> [%d]", event.dest);
                break;
            }
            memset(&event, 0, sizeof(event_t));
        }
    }
}