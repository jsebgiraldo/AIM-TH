#ifndef UI_H
#define UI_H

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "event_router.h"

void ui_init(void);
esp_err_t ui_write_event(event_t *event);


#endif