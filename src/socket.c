#include "socket.h"


#define PRINT_UINT8_BITS(x) do {            \
for (int _i = 7; _i >= 0; _i--) {      \
printf("%d", ((x) >> _i) & 1);     \
}                                       \
printf("\n");                           \
} while(0)


#include "hctp/messageModel.h"

_Noreturn void curiosity_socket_receiveData(void *params) {
    CURIOSITY_STATUS_WAIT_WIFI_DONE();

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

        u16_t len;

        netbuf_data(curiosityNetBuffer, &params, &len);

        for (size_t i = 0; i < len; i++) {
            PRINT_UINT8_BITS(((hctp_message_t)params)[i]);
        }

        netbuf_delete(curiosityNetBuffer);
    }
}
