valgrind:
	gcc -g memory_leak.c -o memory_leak.out

asan:
	gcc -fsanitize=address -g memory_leak.c -o memory_leak.out

clean:
	rm -rf *.out
	rm -rf asan.log*
