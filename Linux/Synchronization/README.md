# List

| Name | Sleep | Usage | Description |
| --- | --- | --- | --- |
| Semaphore | Y | Used as signal or notification(producer&consumer), and ensure the order of execution | Ensure the max #thread in the critical section. The resource can be released by other thread. |
| Mutex | Y | Common usage(longer critical section or resource saving) | Who takes and who should release |
| Spinlock | N | Small critical section or context switch | Busy waiting for CPU usage |
| Read-Write Lock | N | While #reader > #writer | Multiple readers or one writer at the same time |

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

# Read-Write Lock
We can use Read-Write Lock in AP with pthread.

## prototype
```c
#include <pthread.h> // include file
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
// initialize and release
int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr); 
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
```

## example
Please refer to [RWL_example.c](RWL_example.c).

# usage in kernel

* mutually exclusive
  - disable interrupt: `local_irq_disable` and `local_irq_enable`
  - atomic operation
  - spinlock: `spinlock_t`, `spin_lock_init`, `spin_lock`, `spin_unlock`
  - read-write lock: `rwlock_t`, `rwlock_init`, `read_lock`, `read_unlock`, `write_lock`, `write_unlock`
  - mutex(count = 1): `mutex_init`, `mutex_lock`, `mutex_unlock`
  - semaphore: `sema_init`, `up`, `down`
* synchronization
  - semaphore: `sema_init`, `up`, `down`
  - completion: `init_completion`, `wait_for_completion`, `complete`
