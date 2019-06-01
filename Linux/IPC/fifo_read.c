#include <stdio.h>
#include <sys/stat.h> // fifo
#include <errno.h>    // errno
#include <unistd.h>   // read,close
#include <fcntl.h>    // O_RDONLY

int main() {
    int ret = -1;
    char *fifo = "./fifo";
    // Create FIFO
    if (mkfifo(fifo, 0666) != 0 && errno != EEXIST) {
        printf("mkfifo error\n");
        goto exit;
    }
    // Read from FIFO
    char buf[128];
    int fd = open(fifo, O_RDONLY);
    int len = read(fd, buf, sizeof(buf));
    printf("Read len=%d, content=%s\n", len, buf);
    close(fd);
    ret = 0;
exit:
    return ret;
}