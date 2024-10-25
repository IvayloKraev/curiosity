#ifndef CURIOSITY_SOCKET_H
#define CURIOSITY_SOCKET_H

#include <pico/stdio_usb.h>
#include <lwip/api.h>
#include <lwip/netif.h>

#include "status.h"

_Noreturn void curiosity_socket_receiveData();

#endif
