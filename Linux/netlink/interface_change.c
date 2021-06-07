#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <net/if.h>
#include <sys/socket.h>
#include <linux/rtnetlink.h>

static void parseRtattr(struct rtattr *tb[], int max, struct rtattr *rta, int len)
{
    memset(tb, 0, sizeof(struct rtattr *) * (max +1));
    while (RTA_OK(rta, len)) {
        if (rta->rta_type <= max) {
            tb[rta->rta_type] = rta;
        }
        rta = RTA_NEXT(rta, len);
    }
}

int main()
{
    int ret = 0;

    // Create socket for netlink
    int fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (fd < 0) {
        printf("Failed to create socket.\n");
        ret = -1;
        goto exit;
    }

    // Create local address for netlink
    struct sockaddr_nl local;
    memset(&local, 0, sizeof(local));
    local.nl_family = AF_NETLINK;
    local.nl_groups = RTMGRP_LINK; // receive interface change event from kernel
    local.nl_pid = getpid();

    // Create message struct for netlink
    char buf[8192];
    struct iovec iov;
    iov.iov_base = buf;
    iov.iov_len = sizeof(buf);

    // Init protocol message header
    struct msghdr msg;
    msg.msg_name = &local;
    msg.msg_namelen = sizeof(local);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    // Bind the socket
    if (bind(fd, (struct sockaddr*)&local, sizeof(local)) < 0) {
        printf("Failed to bind netlink socket\n");
        close(fd);
        ret = -1;
        goto exit;
    }

    // Receive message from kernel netlink
    while (1) {
        ssize_t recvlen = recvmsg(fd, &msg, MSG_DONTWAIT);
        if (recvlen < 0) {
            sleep(1);
            continue;
        }
        // check the message size
        if (msg.msg_namelen != sizeof(local)) {
            printf("Incorrect message size\n");
            continue;
        }
        // Parse the message
        struct nlmsghdr *h;
        for (h = (struct nlmsghdr*)buf; recvlen >= (ssize_t)sizeof(*h); ) {
            int len = h->nlmsg_len;
            char *ifName;
            char *ifUpp;
            char *ifRunn;
            struct ifinfomsg *ifi;
            struct rtattr *tb[IFLA_MAX+1];

            // Parse information from message
            ifi = (struct ifinfomsg *) NLMSG_DATA(h);
            parseRtattr(tb, IFLA_MAX, IFLA_RTA(ifi), h->nlmsg_len);
            if (tb[IFLA_IFNAME]) {
                ifName = (char *)RTA_DATA(tb[IFLA_IFNAME]);
            }
            ifUpp = (ifi->ifi_flags & IFF_UP)? "UP":"DOWN";
            ifRunn = (ifi->ifi_flags & IFF_RUNNING)? "RUNNING":"NOT RUNNING";
            
            // Check the event type
            switch (h->nlmsg_type) {
                case RTM_DELLINK:
                    printf("The interface %s was removed.\n", ifName);
                    break;
                case RTM_NEWLINK:
                    printf("New interface %s: state: %s %s.\n", ifName, ifUpp, ifRunn);
                    break;
                default:
                    printf("Unregconized event.\n");
                    break;
            }

            recvlen -= NLMSG_ALIGN(len);
            h = (struct nlmsghdr *)((char *)h + NLMSG_ALIGN(len));
        }
    }

exit:
    return ret;
}
