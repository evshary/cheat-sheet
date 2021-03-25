#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

/* 
 * The example use if_nameindex to list network interface.
 * Then use ioctl(..., SIOCFIFFLAGS, ...) to get the property of the interface.
 */
int main (void)
{
    int ret = 0;
    struct if_nameindex *if_nidxs, *intf;
    struct ifreq ifr;
    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&ifr, sizeof(ifr));

    if_nidxs = if_nameindex();
    if ( if_nidxs == NULL ) {
        ret = -1;
        goto exit;
    }
    for (intf = if_nidxs; intf->if_index != 0 || intf->if_name != NULL; intf++) {
        printf("Checking network interface %s: ", intf->if_name);
        strcpy(ifr.ifr_name, intf->if_name);
        ioctl(sockfd, SIOCGIFFLAGS, &ifr);
        // Make sure the network interface is up and running. Also exclude loopback.
        if ((ifr.ifr_flags & IFF_UP) && (ifr.ifr_flags & IFF_RUNNING) && !(ifr.ifr_flags & IFF_LOOPBACK))
            printf("Enable\n");
        else
            printf("Disable\n");
    }
    if_freenameindex(if_nidxs);
exit:
    close(sockfd);
    return ret;
}
