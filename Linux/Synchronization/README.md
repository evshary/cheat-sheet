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