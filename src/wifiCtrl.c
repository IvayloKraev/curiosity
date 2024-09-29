#include "wifiCtrl.h"

void curiosity_wifiCtrl_init()
{
    if(cyw43_arch_init_with_country(CYW43_COUNTRY_BULGARIA) != PICO_OK){
        stdio_printf("Failed");
        return;
    }
    stdio_printf("success");
}
