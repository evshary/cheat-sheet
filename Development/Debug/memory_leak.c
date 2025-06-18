#include <stdlib.h>
#include <stdio.h>

void memory_leak_func() {
    int *ptr = (int *)malloc(100);
    // memory leak
    ptr = (int *)malloc(200);
    free(ptr);
}

int main() {
    memory_leak_func();
    return 0;
}
