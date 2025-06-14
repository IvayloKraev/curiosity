#ifndef CURIOSITY_CONFIG_H
#define CURIOSITY_CONFIG_H

// Wait time
#define MS_BETWEEN_LOOPS 10

// Tasks
#define tskNORMAL_PRIORITY 1
#define tskCRUCIAL_PRIORITY ((configMAX_PRIORITIES - 1) | portPRIVILEGE_BIT)

// Socket
#define WIFI                            1
#define CYW43_COUNTRY_BULGARIA          CYW43_COUNTRY('B', 'G', 0)
#define CYW43_CURRENT_COUNTRY           CYW43_COUNTRY_BULGARIA
#define WIFI_SSID                       "Houston"
#define WIFI_PASSWORD                   "12345678"
#define WIFI_AUTH                       CYW43_AUTH_WPA2_AES_PSK

#endif
