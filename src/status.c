#include "status.h"

static EventGroupHandle_t curiosity_status_eventGroup;

void curiosity_status_init() {
    curiosity_status_eventGroup = xEventGroupCreate();
}

void curiosity_status_waitStatus(EventBits_t bitsToWait) {
    do {
        EventBits_t wifiBit =
                xEventGroupWaitBits(
                    curiosity_status_eventGroup,
                    bitsToWait,
                    pdFALSE,
                    pdTRUE,
                    portMAX_DELAY
                );

        if (wifiBit != 0) return;

        vTaskDelay(10 / portTICK_PERIOD_MS);
    } while (1);
}

void curiosity_status_setStatus(EventBits_t bits) {
    xEventGroupSetBits(curiosity_status_eventGroup, bits);
}
