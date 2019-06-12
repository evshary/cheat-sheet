#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // for usleep

/*
 * In Linux, default rwlock is read lock first.
 * writer lock will starve while there are too many readers.
 * Therefore we should use pthread_rwlockattr_setkind_np to ensure write lock first.
 * However pthread_rwlockattr_setkind_np is non portable, and only works for Linux.
 */
#define WRITE_LOCK_FIRST 0
#define PROC_NUM         5
#define REPEAT_TIMES     5
#define SLEEP_FUNC   usleep(1) // ms

pthread_rwlock_t rwlock;
int global_value;

void* write_func(void* data) {
    for (int i = 0; i < REPEAT_TIMES; i++) {
        pthread_rwlock_wrlock(&rwlock);
        printf("write_func takes rwlock\n");
        global_value++;
        printf("increase global_value to %d\n", global_value);
        printf("write_func releases rwlock\n");
        pthread_rwlock_unlock(&rwlock);
        SLEEP_FUNC;
    }
    pthread_exit(NULL); // leave thread
}

void* read_func(void* data) {
    for (int i = 0; i < REPEAT_TIMES; i++) {
        pthread_rwlock_rdlock(&rwlock);
        printf("read_func %d takes rwlock\n", *(int *)data);
        printf("read_func %d get global_value=%d\n", *(int *)data, global_value);
        printf("read_func %d releases rwlock\n", *(int *)data);
        pthread_rwlock_unlock(&rwlock);
        SLEEP_FUNC;
    }
    pthread_exit(NULL); // leave thread
}

int main() {
    pthread_t r_t[PROC_NUM];
    pthread_t w_t;
    int nums[PROC_NUM];
    global_value = 0;
    // init rwlock
#if WRITE_LOCK_FIRST
    pthread_rwlockattr_t attr;    
    pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
    pthread_rwlock_init(&rwlock, &attr);
#else
    pthread_rwlock_init(&rwlock, NULL);
#endif
    // start thread
    for (int i = 0; i < PROC_NUM; i++) {
        nums[i] = i;
        pthread_create(&r_t[i], NULL, read_func, &nums[i]);
    }
    pthread_create(&w_t, NULL, write_func, NULL);
    // wait for thread done
    for (int i = 0; i < PROC_NUM; i++) {
        pthread_join(r_t[i], NULL);
    }
    pthread_join(w_t, NULL);
    // destroy rwlock
    pthread_rwlock_destroy(&rwlock);
    return 0;
}