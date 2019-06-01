#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <sys/errno.h> // errno
#include <sys/ipc.h> // ftok(...)
#include <sys/shm.h> // shared memory

#define FTOK_ID 999
#define BUF_LEN 1024
int main() {
    int ret = -1;

    // Get IPC ID
    printf("Get IPC ID\n");
    key_t key;
    key = ftok(".", FTOK_ID);
    if (key == -1) {
        printf("Get IPC ID fail\n");
        goto exit;
    }

    // Create shared memory
    printf("Create shared memory\n");
    int shmid = shmget(key, BUF_LEN, IPC_CREAT);
    if (shmid == -1) {
        printf("shmid error errno=%d\n", errno);
        goto exit;
    }

    // Map shared memory address
    printf("Map shared memory address\n");
    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == NULL) {
        printf("shmat error errno=%d\n", errno);
        goto exit;
    }
    // Copy data from shared memory
    printf("Copy data from shared memory\n");
    char buf[BUF_LEN + 1] = {0};
    memcpy(buf, shmaddr, BUF_LEN);
    printf("buf=%s\n", buf);

    // Clean the first byte of shared memory
    printf("Clean the first byte of shared memory\n");
    shmaddr[0] = 0;

    // Unmap shared memory address
    printf("Unmap shared memory address\n");
    shmdt(shmaddr);
exit:
    return ret;
}