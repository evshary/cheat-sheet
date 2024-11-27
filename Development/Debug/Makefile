valgrind:
	gcc -g memory_leak.c -o memory_leak.out

asan:
	gcc -fsanitize=address -g memory_leak.c -o memory_leak.out

ubsan:
	gcc -fsanitize=undefined -g int_overflow.c -o int_overflow.out

clean:
	rm -rf *.out
	rm -rf asan.log*
	rm -rf ubsan.log*
