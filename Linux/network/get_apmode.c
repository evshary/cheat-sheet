#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

#define WIRELESS_INTERFACE "wlp0s20f3"

int main(void)
{
    int sock_fd;
    struct iwreq wreq;

    memset(&wreq, 0, sizeof(struct iwreq));
    sprintf(wreq.ifr_name, "%s", WIRELESS_INTERFACE);

    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Unable to open socket\n");
        return -1;
    }
    if (ioctl(sock_fd, SIOCGIWMODE, &wreq)) {
        printf("Unable to get WiFi mode\n");
        return -1;
    }

    printf("The wifi mode is ");
    // Please refer to https://elixir.bootlin.com/linux/v4.7/source/include/uapi/linux/wireless.h#L448
    switch (wreq.u.mode) {
        case IW_MODE_AUTO:
            printf("auto");
            break;
        case IW_MODE_ADHOC:
            printf("single cell");
            break;
        case IW_MODE_INFRA:
            printf("multi cell");
            break;
        case IW_MODE_MASTER:
            printf("ap mode");
            break;
        case IW_MODE_REPEAT:
            printf("repeater");
            break;
        case IW_MODE_SECOND:
            printf("backup");
            break;
        case IW_MODE_MONITOR:
            printf("passive monitor");
            break;
        case IW_MODE_MESH:
            printf("mesh");
            break;
        default:
            printf("unknown");
            break;
    }
    printf("\n");

    close(sock_fd);

    return 0;
}
