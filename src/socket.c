#include "socket.h"

#include <string.h>

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
