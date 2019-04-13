#include <iostream>
#include <vector>
using namespace std;

#define RADIX 10
#define MAX_RADIX 100
int radix_sort(vector<int> &array) {
    if (array.empty()) return -1;
    vector<int> buckets[RADIX];
    int cur_radix = 1;
    while(cur_radix <= MAX_RADIX) {
        for (auto num : array) {
            int idx = (num/cur_radix) % RADIX;
            buckets[idx].push_back(num);
        }
        int ptr = 0;
        for (int i = 0; i < RADIX; i++) {
            for (auto num : buckets[i])
                array[ptr++] = num;
            buckets[i].clear();
        }
        cur_radix *= RADIX;
    }
    return 0;
}

int main() {
    vector<int> array{72,99,6,25,17,22,35,64,12,98,12};
    radix_sort(array);
    for (auto num : array)
        cout << num << " ";
    cout << endl;
    return 0;
}