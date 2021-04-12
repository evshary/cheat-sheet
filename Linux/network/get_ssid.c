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
    sprintf(wreq.ifr_name, WIRELESS_INTERFACE);

    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Unable to open socket\n");
        return -1;
    }
    wreq.u.essid.pointer = malloc(IW_ESSID_MAX_SIZE+1);
    wreq.u.essid.length = IW_ESSID_MAX_SIZE;
    if (ioctl(sock_fd, SIOCGIWESSID, &wreq)) {
        printf("Unable to get ESSID\n");
        return -1;
    }
    printf("The SSID of the interface %s is %s\n", WIRELESS_INTERFACE, (char *)(wreq.u.essid.pointer));

    free(wreq.u.essid.pointer);
    close(sock_fd);

    return 0;
}
