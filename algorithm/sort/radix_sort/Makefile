all: c cpp run

cpp:
	g++ -std=c++11 radix_sort.cpp -o radix_sort_cpp.out

c:
	gcc radix_sort.c -o radix_sort.out

run:
	@echo "C:"
	@./radix_sort.out
	@echo "CPP:"
	@./radix_sort_cpp.out

clean:
	rm *.out