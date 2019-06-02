#include <stdio.h>
#include <string.h>
#include <sys/socket.h> // socket(...), recv, send
#include <sys/un.h>     // struct sockaddr_un
#include <unistd.h>     // unlink, close

#define SOCKET_FILE_NAME "test.socket"
#define BUF_SIZE 1024
int main() {
    int ret = -1;

    // Create socket, we should use AF_UNIX instead of AF_INET
    printf("Create AF_UNIX socket\n");
    int s_fd = socket(AF_UNIX , SOCK_STREAM , 0);
    if (s_fd < 0) {
        printf("Fail to create socket\n");
        goto exit;
    }

    // Build address
    printf("Build the address\n");
    unlink(SOCKET_FILE_NAME); // remove the socket file if it exists
    struct sockaddr_un un_addr;
    bzero(&un_addr, sizeof(un_addr));
    un_addr.sun_family = AF_UNIX;
    strcpy(un_addr.sun_path, SOCKET_FILE_NAME);
    
    // Bind the address
    printf("Bind the address\n");
    if (bind(s_fd, (struct sockaddr *)&un_addr, sizeof(un_addr)) != 0) { 
        printf("Fail to bind address\n"); 
        goto exit;
    }

    // Listen to address
    printf("Listen to address\n");
    if (listen(s_fd, 10) != 0) { // backlog = 10
        printf("Fail to listen\n");
        goto exit;
    }

    // Accept the connection
    printf("Accept the connection\n");
    struct sockaddr_un client_addr;
    socklen_t addr_size;
    int c_fd = accept(s_fd, (struct sockaddr *)&client_addr, &addr_size);
    if (c_fd < 0) {
        printf("Fail to accept\n");
        goto exit;
    }

    // Recv data
    printf("Server received data\n");
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    if ((ret = recv(c_fd, buf, sizeof(buf), 0)) < 0) {
        printf("Recv fail\n");
        goto exit;
    }
    printf("Recv %d bytes: %s\n", ret, buf);
    // Send data
    printf("Server sent data\n");
    char *msg = "Server data!";
    if ((ret = send(c_fd, msg, strlen(msg) , 0)) < 0) {
        printf("Send fail\n");
        goto exit;
    }
    printf("Send %d bytes: %s\n", ret, msg);

    ret = 0;
exit:
    if (s_fd >= 0) close(s_fd);
    return ret;
}