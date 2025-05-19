#ifndef CURIOSITY_SOCKET_H
#define CURIOSITY_SOCKET_H

#include <pico/stdlib.h>
#include <pico/stdio_usb.h>
#include <pico/cyw43_arch.h>
#include <lwip/api.h>
#include <lwip/netif.h>

#include "FreeRTOS.h"
#include "task.h"

#include "hcst/message.h"

#include "config.h"

_Noreturn void curiosity_socket_init();
_Noreturn void curiosity_socket_receive();

#endif
