#include "execute.h"

_Noreturn void curiosity_execute_loop(void *params) {
    hctp_message_t msg = (hctp_message_t)params;

    gpio_init(CURIOSITY_FORWARD_LEFT_PIN);
    gpio_set_dir(CURIOSITY_FORWARD_LEFT_PIN, GPIO_OUT);

    gpio_init(CURIOSITY_BACKWARD_LEFT_PIN);
    gpio_set_dir(CURIOSITY_BACKWARD_LEFT_PIN, GPIO_OUT);

    gpio_init(CURIOSITY_FORWARD_RIGHT_PIN);
    gpio_set_dir(CURIOSITY_FORWARD_RIGHT_PIN, GPIO_OUT);

    gpio_init(CURIOSITY_BACKWARD_RIGHT_PIN);
    gpio_set_dir(CURIOSITY_BACKWARD_RIGHT_PIN, GPIO_OUT);

    while (1) {
        CURIOSITY_STATUS_WAIT_COMMAND();

        if(hctp_control_get_leftTurn(msg)) {
            curiosity_execute_left(hctp_speed_get(msg));
            stdio_printf("left\n");
        }
        else if(hctp_control_get_rightTurn(msg)) {
            curiosity_execute_right(hctp_speed_get(msg));
            stdio_printf("right\n");
        }
        else if(hctp_control_get_stateMotors(msg)) {
            curiosity_execute_forward(hctp_speed_get(msg));
            stdio_printf("forward\n");
        }
        else {
            curiosity_execute_stop();
            stdio_printf("stop\n");
        }
    }
}


void curiosity_execute_forward(uint8_t speed) {
    gpio_put(CURIOSITY_BACKWARD_LEFT_PIN, 0);
    gpio_put(CURIOSITY_BACKWARD_RIGHT_PIN, 0);

    gpio_put(CURIOSITY_FORWARD_LEFT_PIN, 1);
    gpio_put(CURIOSITY_FORWARD_RIGHT_PIN, 1);

    curiosity_execute_speed(speed);
}
void curiosity_execute_stop() {
    gpio_put(CURIOSITY_FORWARD_LEFT_PIN, 0);
    gpio_put(CURIOSITY_FORWARD_RIGHT_PIN, 0);

    gpio_put(CURIOSITY_BACKWARD_LEFT_PIN, 1);
    gpio_put(CURIOSITY_BACKWARD_RIGHT_PIN, 1);

    curiosity_execute_speed(0);
}
void curiosity_execute_left(uint8_t speed) {
    gpio_put(CURIOSITY_BACKWARD_RIGHT_PIN, 0);
    gpio_put(CURIOSITY_FORWARD_LEFT_PIN, 0);

    gpio_put(CURIOSITY_FORWARD_RIGHT_PIN, 1);
    gpio_put(CURIOSITY_BACKWARD_LEFT_PIN, 1);

    curiosity_execute_speed(speed);
}

void curiosity_execute_right(uint8_t speed) {
    gpio_put(CURIOSITY_FORWARD_RIGHT_PIN, 0);
    gpio_put(CURIOSITY_BACKWARD_LEFT_PIN, 0);

    gpio_put(CURIOSITY_BACKWARD_RIGHT_PIN, 1);
    gpio_put(CURIOSITY_FORWARD_LEFT_PIN, 1);

    curiosity_execute_speed(speed);
}

void curiosity_execute_speed(uint8_t speed) {

}
