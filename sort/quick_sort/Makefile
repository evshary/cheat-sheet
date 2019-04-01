all: c cpp run

cpp:
	g++ -std=c++11 quick_sort.cpp -o quick_sort_cpp.out

c:
	gcc quick_sort.c -o quick_sort.out

run:
	@echo "C:"
	@./quick_sort.out
	@echo "CPP:"
	@./quick_sort_cpp.out

clean:
	rm *.out