#include <stdio.h>
#include <pthread.h>

#define REPEAT_TIMES 5

#ifdef USE_MUTEX
    pthread_mutex_t mutex;
#endif
#ifdef USE_SPINLOCK
    pthread_spinlock_t spinlock;
#endif

void* t1_func(void* data) {
    for (int i = 0; i < REPEAT_TIMES; i++) {
#ifdef USE_MUTEX
        pthread_mutex_lock(&mutex);
#endif
#ifdef USE_SPINLOCK
        pthread_spin_lock(&spinlock);
#endif
        printf("t1 takes the lock\n");
        printf("t1 do something...\n");
        printf("t1 release the lock\n");
#ifdef USE_MUTEX
        pthread_mutex_unlock(&mutex);
#endif
#ifdef USE_SPINLOCK
        pthread_spin_unlock(&spinlock);
#endif
    }
    pthread_exit(NULL); // leave thread
}

void* t2_func(void* data) {
    for (int i = 0; i < REPEAT_TIMES; i++) {
#ifdef USE_MUTEX
        pthread_mutex_lock(&mutex);
#endif
#ifdef USE_SPINLOCK
        pthread_spin_lock(&spinlock);
#endif
        printf("t2 takes the lock\n");
        printf("t2 do something...\n");
        printf("t2 release the lock\n");
#ifdef USE_MUTEX
        pthread_mutex_unlock(&mutex);
#endif
#ifdef USE_SPINLOCK
        pthread_spin_unlock(&spinlock);
#endif
    }
    pthread_exit(NULL); // leave thread
}

int main() {
    pthread_t t1, t2;
    // Create synchronization
#ifdef USE_MUTEX
    pthread_mutex_init(&mutex, NULL);
#endif
#ifdef USE_SPINLOCK
    pthread_spin_init(&spinlock, 0);
#endif
    // Create thread
    pthread_create(&t1, NULL, t1_func, NULL);
    pthread_create(&t2, NULL, t2_func, NULL);
    // Join the thread
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // Destroy synchronization
#ifdef USE_MUTEX
    pthread_mutex_destroy(&mutex);
#endif
#ifdef USE_SPINLOCK
    pthread_spin_destroy(&spinlock);
#endif
    return 0;
}