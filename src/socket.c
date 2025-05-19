#include "socket.h"

_Noreturn void curiosity_socket_init() {
#if WIFI
    if (cyw43_arch_init_with_country(CYW43_CURRENT_COUNTRY)) {
        stdio_printf("failed to initialise wifi\n");
        vTaskDelete(NULL);
    }

    cyw43_arch_enable_sta_mode();
    stdio_printf("sta mode enabled\n");

    if (cyw43_arch_wifi_connect_blocking(WIFI_SSID, WIFI_PASSWORD, WIFI_AUTH) != PICO_OK) {
        stdio_printf("failed to connect to ap\n");
    }
#elif BT

#elif RADIO

#endif
        vTaskDelete(NULL);
}

_Noreturn void curiosity_socket_receive() {
    const ip_addr_t *curiosityIpAddr = netif_ip4_addr(netif_default);

    // Creating connection
    struct netconn *curiosityUdpConnection = netconn_new(NETCONN_UDP);

    err_t netconnStatus = netconn_bind(curiosityUdpConnection, curiosityIpAddr, 784);

    if (netconnStatus != ERR_OK) {
        stdio_printf("netconn_bind failed\n");
        vTaskDelete(NULL);
    }

    struct netbuf *curiosityNetBuffer;

    while (1) {
        err_t m = netconn_recv(curiosityUdpConnection, &curiosityNetBuffer);

        if (m != ERR_OK) {
            stdio_printf("netconn_recv failed\n");
        }

        void *data;
        u16_t len;
        netbuf_data(curiosityNetBuffer, &data, &len);

        if(len != HCTP_MESSAGE_SIZE_BYTES) {
            stdio_printf("netbuf_data failed\n");
            netbuf_delete(curiosityNetBuffer);
            continue;
        }

        (void) memcpy((void *) params, (const void *) data, (size_t) HCTP_MESSAGE_SIZE_BYTES);

        CURIOSITY_STATUS_SET_COMMAND();

        netbuf_delete(curiosityNetBuffer);
    }
}
