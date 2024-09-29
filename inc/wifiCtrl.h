#ifndef CURIOSITY_WIFICTRL_H
#define CURIOSITY_WIFICTRL_H

#include "pico/stdlib.h"
#include "pico/stdio_usb.h"
#include "pico/cyw43_arch.h"

#define CYW43_COUNTRY_BULGARIA CYW43_COUNTRY('B', 'G', 0)

void curiosity_wifiCtrl_init();

#endif
