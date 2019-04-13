#include <stdio.h>
#include <stdbool.h>

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void bubble_sort(int *array, int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        bool swap_flag = false;
        for (int j = 1; j < arr_len - i; j++) {
            if (array[j-1] > array[j]) {
                swap(&array[j-1], &array[j]);
                swap_flag = true;
            }
        }
        if (!swap_flag)
            break;
    }
}

int main() {
    int array[] = {98,88,96,93,65,81,82,29,9,21};
    int arr_len = sizeof(array)/sizeof(arr_len);
    bubble_sort(array, arr_len);
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}