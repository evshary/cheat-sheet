#include <stdio.h>
#include <string.h>
#include <sys/socket.h> // socket(...), recv, send
#include <netinet/in.h> // struct sockaddr_in
#include <arpa/inet.h>  // inet_addr(...)
#include <unistd.h>     // close

#define BUF_SIZE 1024
#define SERVER_PORT 1234
int main(int argc, char *argv[])
{
    int ret;
    // create socket
    int fd = socket(AF_INET , SOCK_STREAM , 0);
    if (fd < 0) {
        printf("Fail to create socket");
        goto exit;
    }
    // build address
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);
    // connect to server
    ret = connect(fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        printf("Fail to connect\n");
        goto exit;
    }
    // send and recv data
    char *msg = "client sent!";
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    // send
    if ((ret = send(fd, msg, strlen(msg) , 0)) < 0) {
        printf("Send fail\n");
        goto exit;
    }
    printf("Send %d bytes: %s\n", ret, msg);
	// recv
    if ((ret = recv(fd, buf, sizeof(buf), 0)) < 0) {
        printf("Recv fail\n");
        goto exit;
    }
    printf("Recv %d bytes: %s\n", ret, buf);
exit:
    if (fd >= 0) close(fd);
    return 0;
}