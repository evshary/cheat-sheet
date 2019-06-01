#include <stdio.h>
#include <stddef.h>
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
    volatile char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        printf("shmat error errno=%d\n", errno);
        goto exit;
    }

    // Copy data into shared memory
    printf("Copy data into shared memory\n");
    for (int i = 0; i < BUF_LEN; i++)
        shmaddr[i] = 'a';

    // Wait for another process to change
    printf("Wait for another process to change\n");
    while (shmaddr[0] != 0);

    // Unmap shared memory address
    printf("Unmap shared memory address\n");
    shmdt((const void *)shmaddr);
    
    ret = 0;
exit:
    return ret;
}