# List
| Name | Feature |
| --- | --- |
| Shared Memory | fastest, synchronization needed, Live with kernel |
| PIPE |  |
| FIFO |  |
| Message Queue |  |
| Unix Socket |  |

# Shared Memory
## prototype
```c
#include <sys/shm.h> // include file
// Create/Get a shared memory segmnet
// Return: shared memory ID, or -1 while fail
int shmget(key_t key, size_t size, int shmflg);
// Map shared memory
// Return: return mapping address, or -1 while fail
void *shmat(int shmid, const void *shmaddr, int shmflg);
// Unmap shared memory
// Return: success with 0, fail with -1
int shmdt(const void *shmaddr);
// Shared memory control operations
// Return: success with 0, fail with -1
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```
## example
Please refer to [shm_proc1.c](shm_proc1.c) and [shm_proc2.c](shm_proc2.c).

**You should use root privilege to run the program.**

# PIPE

# FIFO

# Mesage Queue

# Unix Socket
