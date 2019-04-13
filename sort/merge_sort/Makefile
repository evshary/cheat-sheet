all: c cpp run

cpp:
	g++ -std=c++11 merge_sort.cpp -o merge_sort_cpp.out

c:
	gcc merge_sort.c -o merge_sort.out

run:
	@echo "C:"
	@./merge_sort.out
	@echo "CPP:"
	@./merge_sort_cpp.out

clean:
	rm *.out