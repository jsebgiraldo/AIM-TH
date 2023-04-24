#ifndef LIGHT_H
#define LIGHT_H

#include <stdint.h>

void light_init(void);
void light_on(void);
void light_off(void);
void light_on_with_timeout(uint32_t tick_ms);


#endif