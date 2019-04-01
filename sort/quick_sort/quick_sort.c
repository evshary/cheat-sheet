#include <stdio.h>

void swap(int *num1, int *num2) {
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void quick_sort_r(int *nums, int start, int end) {
    int pivot = start;
    int i = start, j = end+1;
    if (start >= end)
        return;
    while (1) {
        while(j > start && nums[--j] > nums[pivot]);
        while(i < end && nums[++i] < nums[pivot]);
        if (i >= j) break;
        swap(&nums[i], &nums[j]);
    }
    swap(&nums[j], &nums[pivot]);
    quick_sort_r(nums, start, j-1);
    quick_sort_r(nums, j+1, end);
}

void quick_sort(int *nums, int nums_size) {
    quick_sort_r(nums, 0, nums_size-1);
}

int main() {
    int nums[] = {5,6,3,1,-4,5,8,3};
    int nums_size = sizeof(nums)/sizeof(nums[0]);
    quick_sort(nums, nums_size);
    for (int i = 0; i < nums_size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}