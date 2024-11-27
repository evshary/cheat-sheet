#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MAX; // Max value for 32-bit int
    int b = a + 1;   // Signed integer overflow
    printf("Result: %d\n", b);
    return 0;
}
