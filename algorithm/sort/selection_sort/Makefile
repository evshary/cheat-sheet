all: c cpp run

cpp:
	g++ -std=c++11 selection_sort.cpp -o selection_sort_cpp.out

c:
	gcc selection_sort.c -o selection_sort.out

run:
	@echo "C:"
	@./selection_sort.out
	@echo "CPP:"
	@./selection_sort_cpp.out

clean:
	rm *.out