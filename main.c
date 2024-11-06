#include "pico/stdlib.h"
#include "pico/stdio_usb.h"

#include "FreeRTOS.h"
#include "task.h"

#include "hctp/messageModel.h"

#include "common.h"
#include "wifiCtrl.h"
#include "socket.h"
#include "execute.h"

static wifiConfig_t wifiConfig = {
    .ssid = "Houston",
    .password = "12345678"
};

static hctp_message_t curiosity_message = {};

int main(void)
{
    stdio_usb_init();

    sleep_ms(5000);

    stdio_printf("Start init\n");

    hctp_message_init(curiosity_message);

    curiosity_status_init();

    stdio_printf("Start loop logic\n");

    xTaskCreate(
            curiosity_wifiCtrl_init,
            "curiosity_wifiCtrl_init",
            configMINIMAL_STACK_SIZE,
            &wifiConfig,
            tskCRUCIAL_PRIORITY,
            NULL
            );

    xTaskCreate(
           curiosity_socket_receiveData,
           "curiosity_socket_receiveData",
           configMINIMAL_STACK_SIZE,
           curiosity_message,
           tskNORMAL_PRIORITY,
           NULL
           );

    xTaskCreate(
        curiosity_execute_loop,
        "curiosity_execute_loop",
        configMINIMAL_STACK_SIZE,
        curiosity_message,
        tskNORMAL_PRIORITY,
        NULL
        );

    vTaskStartScheduler();
    return 0;
}
