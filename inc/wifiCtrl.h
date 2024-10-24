#ifndef CURIOSITY_WIFICTRL_H
#define CURIOSITY_WIFICTRL_H

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "pico/cyw43_arch.h"

#include "FreeRTOS.h"
#include "task.h"

#include "status.h"

#define CYW43_COUNTRY_BULGARIA CYW43_COUNTRY('B', 'G', 0)

typedef struct {
    const char *ssid;
    const char *password;
} wifiConfig_t;

typedef wifiConfig_t *wifiConfigHandler_t;

void curiosity_wifiCtrl_init();

#endif
