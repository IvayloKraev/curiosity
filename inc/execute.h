#ifndef CURIOSITY_EXECUTE_H
#define CURIOSITY_EXECUTE_H

#include <stdint.h>

#include <hardware/gpio.h>
#include <hardware/adc.h>

#include "hctp/messageModel.h"

// A - left
// B - right

#define CURIOSITY_FORWARD_LEFT_PIN 2
#define CURIOSITY_BACKWARD_LEFT_PIN 3
#define CURIOSITY_FORWARD_RIGHT_PIN 4
#define CURIOSITY_BACKWARD_RIGHT_PIN 5

#define CURIOSITY_SPEED_LEFT_ADC 0
#define CURIOSITY_SPEED_RIGHT_ADC 1

#define CURIOSITY_SPEED_LEFT_PIN (CURIOSITY_SPEED_LEFT_ADC + 26)
#define CURIOSITY_SPEED_RIGHT_PIN (CURIOSITY_SPEED_RIGHT_ADC + 26)

_Noreturn void curiosity_execute_loop(void *);

void curiosity_execute_forward(uint8_t);
void curiosity_execute_stop();
void curiosity_execute_left(uint8_t);
void curiosity_execute_right(uint8_t);
void curiosity_execute_speed(uint8_t);


#endif
