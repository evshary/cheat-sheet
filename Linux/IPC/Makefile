all: shm msgq pipe fifo socket

shm:
	gcc shm_proc1.c -o shm_proc1.out
	gcc shm_proc2.c -o shm_proc2.out

msgq:
	gcc msgq_server.c -o msgq_server.out
	gcc msgq_client.c -o msgq_client.out

pipe:
	gcc pipe.c -o pipe.out

fifo:
	gcc fifo_read.c -o fifo_read.out
	gcc fifo_write.c -o fifo_write.out

socket:
	gcc uds_server.c -o uds_server.out
	gcc uds_client.c -o uds_client.out

clean:
	rm *.out