all: shm msgq pipe

shm:
	gcc shm_proc1.c -o shm_proc1.out
	gcc shm_proc2.c -o shm_proc2.out

msgq:
	gcc msgq_server.c -o msgq_server.out
	gcc msgq_client.c -o msgq_client.out

pipe:
	gcc pipe.c -o pipe.out

clean:
	rm *.out