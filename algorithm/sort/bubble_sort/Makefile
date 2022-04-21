all: c cpp run

cpp:
	g++ -std=c++11 bubble_sort.cpp -o bubble_sort_cpp.out

c:
	gcc bubble_sort.c -o bubble_sort.out

run:
	@echo "C:"
	@./bubble_sort.out
	@echo "CPP:"
	@./bubble_sort_cpp.out

clean:
	rm *.out