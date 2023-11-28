all: thread.out fork.out

thread.out: thread.c
	gcc thread.c -lpthread -o thread.out

fork.out: fork.c
	gcc fork.c -o fork.out

clean:
	rm *.out
