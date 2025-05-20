#ifndef CURIOSITY_EXECUTE_H
#define CURIOSITY_EXECUTE_H

#include <stdint.h>

#include <pico/stdio_usb.h>

#include <hardware/gpio.h>
#include <hardware/pwm.h>

#include <hcst/message.h>
#include <hcst/state.h>

#include "common.h"

// A - left
// B - right

#define CURIOSITY_FORWARD_LEFT_PIN 2
#define CURIOSITY_BACKWARD_LEFT_PIN 3
#define CURIOSITY_FORWARD_RIGHT_PIN 4
#define CURIOSITY_BACKWARD_RIGHT_PIN 5

#define CURIOSITY_SPEED_LEFT_PIN 27
#define CURIOSITY_SPEED_RIGHT_PIN 26

_Noreturn void curiosity_execute_init();
_Noreturn void curiosity_execute_loop(void *);

#endif
