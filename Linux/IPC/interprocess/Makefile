all: shm msgq pipe.out fifo socket

shm: shm_proc1.out shm_proc2.out

shm_proc1.out: shm_proc1.c
	gcc shm_proc1.c -o shm_proc1.out

shm_proc2.out: shm_proc2.c
	gcc shm_proc2.c -o shm_proc2.out

msgq: msgq_server.out msgq_client.out

msgq_server.out: msgq_server.c
	gcc msgq_server.c -o msgq_server.out

msgq_client.out: msgq_client.c
	gcc msgq_client.c -o msgq_client.out

pipe.out: pipe.c
	gcc pipe.c -o pipe.out

fifo: fifo_read.out fifo_write.out

fifo_read.out: fifo_read.c
	gcc fifo_read.c -o fifo_read.out

fifo_write.out: fifo_write.c
	gcc fifo_write.c -o fifo_write.out

socket: uds_server.out uds_client.out

uds_server.out: uds_server.c
	gcc uds_server.c -o uds_server.out

uds_client.out: uds_client.c
	gcc uds_client.c -o uds_client.out

clean:
	rm *.out