#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int get_ip(char *interface, char *myip, int myip_len)
{
    int fd;
    struct ifreq ifr;
   
    fd = socket(AF_INET, SOCK_DGRAM, 0);
   
    ifr.ifr_addr.sa_family = AF_INET; // get IPv4 address
    strncpy(ifr.ifr_name, "enp1s0", IFNAMSIZ-1); // get IP from certain interface
    ioctl(fd, SIOCGIFADDR, &ifr); // get IP
   
    close(fd);

    strncpy(myip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr), myip_len-1);
    myip[myip_len-1] = 0;
   
    return 0;
}

int main()
{
    char myip[50];
    get_ip("enp1s0", myip, sizeof(myip));
    printf("My IP is %s\n", myip);
    return 0;
}
