#include "execute.h"

_Noreturn void curiosity_execute_init() {
    gpio_init(CURIOSITY_FORWARD_LEFT_PIN);
    gpio_set_dir(CURIOSITY_FORWARD_LEFT_PIN, GPIO_OUT);

    gpio_init(CURIOSITY_BACKWARD_LEFT_PIN);
    gpio_set_dir(CURIOSITY_BACKWARD_LEFT_PIN, GPIO_OUT);

    gpio_init(CURIOSITY_FORWARD_RIGHT_PIN);
    gpio_set_dir(CURIOSITY_FORWARD_RIGHT_PIN, GPIO_OUT);

    gpio_init(CURIOSITY_BACKWARD_RIGHT_PIN);
    gpio_set_dir(CURIOSITY_BACKWARD_RIGHT_PIN, GPIO_OUT);

    gpio_set_function(CURIOSITY_SPEED_LEFT_PIN, GPIO_FUNC_PWM);
    gpio_set_function(CURIOSITY_SPEED_RIGHT_PIN, GPIO_FUNC_PWM);

    // Get the PWM slices associated with the GPIO pins
    uint speedLeftSlice = pwm_gpio_to_slice_num(CURIOSITY_SPEED_LEFT_PIN);
    uint speedRightSlice = pwm_gpio_to_slice_num(CURIOSITY_SPEED_RIGHT_PIN);

    // Configure PWM for the first pin
    pwm_config config1 = pwm_get_default_config();
    pwm_config_set_clkdiv(&config1, 4.0f);  // Adjust to set frequency for pin 1
    pwm_config_set_wrap(&config1, 255);    // Set duty cycle resolution for pin 1
    pwm_init(speedLeftSlice, &config1, true);

    // Configure PWM for the second pin
    pwm_config config2 = pwm_get_default_config();
    pwm_config_set_clkdiv(&config2, 4.0f);  // Adjust to set frequency for pin 2
    pwm_config_set_wrap(&config2, 255);    // Set duty cycle resolution for pin 2
    pwm_init(speedRightSlice, &config2, true);
}

_Noreturn void curiosity_execute_loop(void *params) {
    const receiveMessageFn_t receive = params;

    while (1) {
        hcst_message_t message;
        hcst_MESSAGE_INIT(message);
        const BaseType_t receiveStatus = receive(message);

        if(receiveStatus == pdPASS) {
            continue;
        }

        const bool flmPowered = hcst_powerMotor_get(message, hcst_FLM_BIT);
        const bool frmPowered = hcst_powerMotor_get(message, hcst_FRM_BIT);
        const bool rlmPowered = hcst_powerMotor_get(message, hcst_RLM_BIT);
        const bool rrmPowered = hcst_powerMotor_get(message, hcst_RRM_BIT);

        const bool flmDirection = hcst_directionMotor_get(message, hcst_FLM_BIT);
        const bool frmDirection = hcst_directionMotor_get(message, hcst_FRM_BIT);
        const bool rlmDirection = hcst_directionMotor_get(message, hcst_RLM_BIT);
        const bool rrmDirection = hcst_directionMotor_get(message, hcst_RRM_BIT);

        const uint8_t speed = hcst_speed_get(message);
    }
}
