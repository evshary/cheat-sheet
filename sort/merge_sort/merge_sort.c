#include <stdio.h>
#include <stdlib.h>

void merge_sort_r(int *array, int *tmp_array, int start, int end) {
    if (start == end)
        return;
    int middle = (start + end)/2;
    merge_sort_r(array, tmp_array, start, middle);
    merge_sort_r(array, tmp_array, middle+1, end);
    int arr_ptr = start, sub_ptr1 = start, sub_ptr2 = middle+1;
    for (int i = start; i <= end; i++) {
        if (sub_ptr1 <= middle && sub_ptr2 > end) {
            tmp_array[arr_ptr++] = array[sub_ptr1++];
        } else if (sub_ptr1 > middle && sub_ptr2 <= end) {
            tmp_array[arr_ptr++] = array[sub_ptr2++];
        } else {
            if (array[sub_ptr1] <= array[sub_ptr2])
                tmp_array[arr_ptr++] = array[sub_ptr1++];
            else
                tmp_array[arr_ptr++] = array[sub_ptr2++];
        }
    }
    for (int i = start; i <= end; i++)
        array[i] = tmp_array[i];
}

void merge_sort(int *array, int arr_len) {
    int *tmp_array = malloc(arr_len * sizeof(int));
    if (!tmp_array) return;
    merge_sort_r(array, tmp_array, 0, arr_len-1);
    free(tmp_array);
}

int main() {
    int array[] = {66,62,76,52,74,57,52,38,28,7};
    int arr_len = sizeof(array)/sizeof(array[0]);
    merge_sort(array, arr_len);
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}