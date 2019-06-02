#include <stdio.h>
#include <semaphore.h> // semaphore
#include <pthread.h> // pthread
#include <unistd.h> // sleep

#define SEMA_NAME "./my_semaphore"
#define SEMA_VALUE 1 // binary semaphore
#define REPEAT_TIMES 5

sem_t* sema_ptr;

void* proc_func1(void* data) {
    for (int i = 0; i < REPEAT_TIMES; i++) {
        if(sem_wait(sema_ptr) < 0) {
            printf("sem_wait error\n");
        }
        printf("This is thread1\n");
        if(sem_post(sema_ptr) < 0) {
            printf("sem_post error\n");
        }
    }
    pthread_exit(NULL); // leave thread
}

void* proc_func2(void* data) {
    for (int i = 0; i < REPEAT_TIMES; i++) {
        if(sem_wait(sema_ptr) < 0) {
            printf("sem_wait error\n");
        }
        printf("This is thread2\n");
        if(sem_post(sema_ptr) < 0) {
            printf("sem_post error\n");
        }
    }
    pthread_exit(NULL); // leave thread
}

int main() {
    int ret = -1;

    // Init semaphore
    printf("Init semaphore\n");
    if ((sema_ptr = sem_open(SEMA_NAME, O_CREAT, 0600, SEMA_VALUE)) == SEM_FAILED) {
        printf("sem_open fail\n");
        goto exit;
    }

    // Take the semaphore
    printf("Main thread takes the semaphore\n");
    if(sem_wait(sema_ptr) < 0) {
        printf("sem_wait error\n");
    }

    // Create thread
    printf("Create thread\n");
    pthread_t t1, t2;
    pthread_create(&t1, NULL, proc_func1, NULL);
    pthread_create(&t2, NULL, proc_func2, NULL);

    // Main thread sleeps 3 seconds and then release the semaphore
    printf("Main thread sleeps 3 seconds and then release the semaphore\n");
    sleep(3);
    if(sem_post(sema_ptr) < 0) {
        printf("sem_post error\n");
    }

    // Wait for thread
    printf("Wait for thread\n");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Close semaphore
    printf("Close semaphore\n");
    sem_close(sema_ptr);
    sem_unlink(SEMA_NAME);
    
    ret = 0;
exit:
    return ret;
}