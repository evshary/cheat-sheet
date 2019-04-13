#include <stdio.h>

void insertion_sort(int *array, int arr_len) {
    int i, j, tmp;
    for (i = 1; i < arr_len; i++) {
        tmp = array[i];
        for (j = i; j > 0 && tmp < array[j-1]; j--) {
            array[j] = array[j-1];
        }
        array[j] = tmp;
    }
}

int main() {
    int array[] = {71,3,25,83,27,8,100,40,78,36};
    int arr_len = sizeof(array)/sizeof(array[0]);
    insertion_sort(array, arr_len);
    for (int i = 0; i < arr_len; i++) {    
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}