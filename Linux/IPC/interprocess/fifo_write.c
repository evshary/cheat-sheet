#include <stdio.h>
#include <string.h>
#include <unistd.h>   // write,close
#include <sys/stat.h> // fifo
#include <fcntl.h>    // O_WRONLY

int main() {
    int ret = -1;
    char *fifo = "./fifo";
 
    // Just write to FIFO, no need to create FIFO
    char *msg = "This is message";
    int fd = open(fifo, O_WRONLY);
    printf("Write message to fifo read\n");
    int len = write(fd, msg, strlen(msg));
    close(fd);
    ret = 0;
exit:
    return ret;
}