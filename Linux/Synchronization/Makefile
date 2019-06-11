all: sem_example.out mutex_example.out spinlock_example.out

sem_example.out: sem_example.c
	gcc sem_example.c -lpthread -o sem_example.out

mutex_example.out: mutex_spinlock_example.c
	gcc mutex_spinlock_example.c -lpthread -DUSE_MUTEX -o mutex_example.out

spinlock_example.out: mutex_spinlock_example.c
	gcc mutex_spinlock_example.c -lpthread -DUSE_SPINLOCK -o spinlock_example.out

clean:
	rm *.out