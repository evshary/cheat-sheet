#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = (int *)malloc(100);
    // memory leak
    ptr = (int *)malloc(200);
    free(ptr);
    return 0;
}
