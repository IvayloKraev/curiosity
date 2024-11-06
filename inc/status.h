#ifndef CURIOSITY_STATUS_H
#define CURIOSITY_STATUS_H

#include "FreeRTOS.h"
#include "event_groups.h"

#define CURIOSITY_STATUS_WIFI_DONE (1 << 0)
#define CURIOSITY_STATUS_COMMAND (1 << 1)

#define CURIOSITY_STATUS_WAIT_WIFI_DONE() curiosity_status_waitStatus(CURIOSITY_STATUS_WIFI_DONE, pdFALSE)
#define CURIOSITY_STATUS_SET_WIFI_DONE() curiosity_status_setStatus(CURIOSITY_STATUS_WIFI_DONE)

#define CURIOSITY_STATUS_WAIT_COMMAND() curiosity_status_waitStatus(CURIOSITY_STATUS_COMMAND, pdTRUE)
#define CURIOSITY_STATUS_SET_COMMAND() curiosity_status_setStatus(CURIOSITY_STATUS_COMMAND)

void curiosity_status_init();

void curiosity_status_waitStatus(EventBits_t, BaseType_t);

void curiosity_status_setStatus(EventBits_t);


#endif
