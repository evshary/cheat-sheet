# List
* Semaphore
* Mutex
* Spinlock

# Semaphore
There are two kind of header for semaphore

* `semaphore.h`: POSIX implementaion, simple and widely used. We should use this.
* `sys/sem.h`: System V implementaion, for compatible.

## prototype
```c
#include <semaphore.h> // include file
sem_t* sem_open(const char *name, int oflag, ...);
int sem_close(sem_t *sem);
int sem_unlink(const char *name); // delete semaphore file
int sem_post(em_t *sem); // release semaphore
int sem_wait(em_t *sem); // take or wait for semaphore
int sem_trywait(em_t *sem); // try take but not wait if unable to take
/* The following API is deprecated by MAC OS*/
int sem_init(sem_t *, int, unsigned int); // deprecated by MAC OS
int sem_getvalue(sem_t * __restrict, int * __restrict); // deprecated by MAC OS
int sem_destroy(sem_t *); // deprecated by MAC OS
```

## example
Please refer to [semaphore_example.c](semaphore_example.c)

# Mutex
We can use mutex in AP with pthread.

## prototype
```c
#include <pthread.h> // include file
int pthread_mutex_lock(pthread_mutex_t *mutex); // lock the mutex
int pthread_mutex_trylock(pthread_mutex_t *mutex); // try to lock the mutex, but not wait if unable to take
int pthread_mutex_unlock(pthread_mutex_t *mutex); // unlock the mutex
// initialize and release
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

## example
Please refer to [mutex_spinlock_example.c](mutex_spinlock_example.c) with definition USE_MUTEX.

# Spinlock
We can use spinlock in AP with pthread. However, MAC OS deprecates the API.

## prototype
```c
#include <pthread.h> // include file
int pthread_spin_lock(pthread_spinlock_t *lock); // lock the spinlock
int pthread_spin_trylock(pthread_spinlock_t *lock); // try to lock the spinlock, but not wait if unable to take
int pthread_spin_unlock(pthread_spinlock_t *lock); // unlock the spinlock
// initialize and release
int pthread_spin_init(pthread_spinlock_t *lock, int pshared); 
int pthread_spin_destroy(pthread_spinlock_t *lock);
```

## example
Please refer to [mutex_spinlock_example.c](mutex_spinlock_example.c) with definition USE_SPINLOCK.