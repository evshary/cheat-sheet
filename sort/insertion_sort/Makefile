all: c cpp run

cpp:
	g++ -std=c++11 insertion_sort.cpp -o insertion_sort_cpp.out

c:
	gcc insertion_sort.c -o insertion_sort.out

run:
	@echo "C:"
	@./insertion_sort.out
	@echo "CPP:"
	@./insertion_sort_cpp.out

clean:
	rm *.out