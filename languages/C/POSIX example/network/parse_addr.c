#include <stdio.h>
#include <sys/socket.h> // socket(...)
#include <netinet/in.h> // struct sockaddr_in
#include <arpa/inet.h>  // inet_addr(...), inet_aton(...), inet_ntoa(...)

int main() {
    struct sockaddr_in addr;
    char *addr_str;

    // transform string to struct sockaddr_in
    if (inet_aton("10.1.2.3", &addr.sin_addr) == 0)
        printf("Wrong address\n");
    // another way to transform into sockaddr_in
    if ((addr.sin_addr.s_addr = inet_addr("10.1.2.3")) == -1)
        printf("May be wrong or 255.255.255.255\n");

    // transform struct sockaddr_in to string
    addr_str = inet_ntoa(addr.sin_addr);
    printf("%s\n", addr_str);

    // You should use the following way to show IPv6
    struct sockaddr_in ipv4;
    char ipv4_str[INET_ADDRSTRLEN];
    struct sockaddr_in6 ipv6;
    char ipv6_str[INET6_ADDRSTRLEN];

    // IPv4
    // transform string to struct sockaddr_in
    if (inet_pton(AF_INET, "10.1.2.3", &(ipv4.sin_addr)) != 1)
        printf("Something wrong with inet_pton\n");
    // transform struct sockaddr_in to string
    if (inet_ntop(AF_INET, &(ipv4.sin_addr), ipv4_str, INET_ADDRSTRLEN) == NULL)
        printf("Something wrong with inet_ntop\n");
    printf("IPv4 address: %s\n", ipv4_str);

    // IPv6
       // transform string to struct sockaddr_in
    if (inet_pton(AF_INET6, "::1", &(ipv6.sin6_addr)) != 1)
        printf("Something wrong with inet_pton\n");
    // transform struct sockaddr_in to string
    if (inet_ntop(AF_INET6, &(ipv6.sin6_addr), ipv6_str, INET_ADDRSTRLEN) == NULL)
        printf("Something wrong with inet_ntop\n");
    printf("IPv6 address: %s\n", ipv6_str);

    return 0;
}