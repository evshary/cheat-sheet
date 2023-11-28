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
    int s_fd = socket(AF_INET , SOCK_STREAM , 0);
    if (s_fd < 0) {
        printf("Fail to create socket\n");
        goto exit;
    }
    // build address
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);
    // bind address:port
    ret = bind(s_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret != 0) { 
        printf("Fail to bind address\n"); 
        goto exit;
    }
    // listen to client
    if (listen(s_fd, 10) != 0) { // backlog = 10
        printf("Fail to listen port\n");
        goto exit;
    }
    // accept the connection
    struct sockaddr_in client_addr;
    socklen_t addr_size;
    int c_fd = accept(s_fd, (struct sockaddr *)&client_addr, &addr_size);
    if (c_fd < 0) {
        printf("Fail to accept\n");
        goto exit;
    }
    // send and recv data
    char *msg = "server sent!";
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    // recv
    if ((ret = recv(c_fd, buf, sizeof(buf), 0)) < 0) {
        printf("Recv fail\n");
        goto exit;
    }
    printf("Recv %d bytes: %s\n", ret, buf);
    // send
    if ((ret = send(c_fd, msg, strlen(msg) , 0)) < 0) {
        printf("Send fail\n");
        goto exit;
    }
    printf("Send %d bytes: %s\n", ret, msg);
exit:
    if (s_fd >= 0) close(s_fd);
    return 0;
}