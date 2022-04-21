#include <stdio.h>

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void selection_sort(int *array, int arr_len) {
    int idx = 0, tmp_min_idx;
    for (int i = 0; i < arr_len; i++) {
        tmp_min_idx = i;
        for (int j = i; j < arr_len; j++) {
            if (array[j] < array[tmp_min_idx]) {
                tmp_min_idx = j;
            }
        }
        swap(&array[i], &array[tmp_min_idx]);
    }
}

int main() {
    int array[] = {31,58,98,28,70,13,79,47,52,14};
    int arr_len = sizeof(array)/sizeof(array[0]);
    selection_sort(array, arr_len);
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", array[i]);
    }
    printf("\r\n");
    return 0;
}