#include <stdio.h>
#include <string.h>
#include <sys/socket.h> // socket(...), recv, send
#include <sys/un.h>     // struct sockaddr_un
#include <unistd.h>     // unlink, close
#include <errno.h>

#define SOCKET_FILE_NAME "test.socket"
#define BUF_SIZE 1024
int main() {
    int ret = -1;

    // Create socket, we should use AF_UNIX instead of AF_INET
    printf("Create AF_UNIX socket\n");
    int fd = socket(AF_UNIX , SOCK_STREAM , 0);
    if (fd < 0) {
        printf("Fail to create socket\n");
        goto exit;
    }

    // Build address
    printf("Build the address\n");
    struct sockaddr_un un_addr;
    bzero(&un_addr, sizeof(un_addr));
    un_addr.sun_family = AF_UNIX;
    strcpy(un_addr.sun_path, SOCKET_FILE_NAME);

    // Connect to server
    printf("Connect to server\n");
    if (connect(fd, (struct sockaddr *)&un_addr, sizeof(un_addr)) < 0) {
        printf("Fail to connect, errno=%d\n", errno);
        goto exit;
    }

    // Send data
    printf("Client sent data\n");
    char *msg = "Client data!";
    if ((ret = send(fd, msg, strlen(msg) , 0)) < 0) {
        printf("Send fail\n");
        goto exit;
    }
    printf("Send %d bytes: %s\n", ret, msg);

    // Recv data
    printf("Client received data\n");
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    if ((ret = recv(fd, buf, sizeof(buf), 0)) < 0) {
        printf("Recv fail\n");
        goto exit;
    }
    printf("Recv %d bytes: %s\n", ret, buf);

    ret = 0;
exit:
    if (fd >= 0) close(fd);
    return 0;
}