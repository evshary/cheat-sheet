#include <stdio.h>
#include <unistd.h> // fork
#include <sys/wait.h> // wait

int main() {
    pid_t pid = fork();

    if (pid > 0) { // parent process
        int child_exit;
        printf("[P] parent process getpid()=%d, child PID=%d\n", getpid(), pid);
        printf("[P] Wait for child to end....\n");
        wait(&child_exit); // prevent child to become zombie process
        printf("[P] The return value from child = %d\n", WEXITSTATUS(child_exit));
    } else if (pid == 0) { // child process
        printf("[C] child process getpid()=%d\n", getpid());
        sleep(5);
        printf("[C] child process end!\n");
    } else {
        printf("fork() error\n");
    }
    return 0;
}