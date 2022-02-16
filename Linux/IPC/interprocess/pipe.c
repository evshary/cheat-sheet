#include <stdio.h>
#include <string.h>
#include <unistd.h> // fork

int main() {
    int ret = -1;
    char buf[128] = {0};
    // create pipe
    int fd[2];
    if (pipe(fd) != 0) {
        printf("pipe() error\n");
        goto exit;
    }

    pid_t pid = fork();

    if (pid > 0) { // parent process
        close(fd[0]); // close unused read
        char *msg = "Hello Child!";
        printf("[P] Write to child\n");
        write(fd[1], msg, strlen(msg));
    } else if (pid == 0) { // child process
        close(fd[1]); // close unused write
        printf("[C] Read from parent\n");
        read(fd[0], buf, sizeof(buf));
        printf("[C] read buf=%s\n", buf);
    } else {
        printf("fork() error\n");
    }
    ret = 0;
exit:
    return ret;
}