#include <stdio.h>

#define RADIX 10
#define MAX_RADIX 100
int radix_sort(int *array, int arr_len) {
    if (arr_len <= 0) return -1;
    int buckets[RADIX][arr_len];
    int buckets_cnt[RADIX] = {0};
    int cur_radix = 1;
    while (cur_radix <= MAX_RADIX) {
        for (int i = 0; i < arr_len; i++) {
            int idx = (array[i] / cur_radix) % RADIX;
            buckets[idx][buckets_cnt[idx]++] = array[i];
        }
        int ptr = 0;
        for (int i = 0; i < RADIX; i++) {
            for (int j = 0; j < buckets_cnt[i]; j++) {
                array[ptr++] = buckets[i][j];
            }
            buckets_cnt[i] = 0;
        }
        cur_radix *= RADIX;
    }
    return 0;
}

int main() {
    int array[] = {72,99,6,25,17,22,35,64,12,98,12};
    int arr_len = sizeof(array)/sizeof(array[0]);
    radix_sort(array, arr_len);
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}