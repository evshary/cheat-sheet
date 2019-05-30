#include <stdio.h>
#include <pthread.h>

#define PROC_NUM 5

void* proc_func(void* data) {
    printf("This is thread %d\n", *(int *)data);
    pthread_exit(NULL); // leave thread
}

int main() {
    pthread_t t[PROC_NUM];
    int nums[PROC_NUM];
    // start thread
    for (int i = 0; i < PROC_NUM; i++) {
        nums[i] = i;
        pthread_create(&t[i], NULL, proc_func, &nums[i]);
    }
    // wait for thread done
    for (int i = 0; i < PROC_NUM; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}