#include <iostream>
#include <vector>
using namespace std;

void quick_sort_r(vector<int> &array, int start, int end) {
    int pivot = start;
    int i = start, j = end+1;
    if (start >= end)
        return;
    while(true) {
        while(j > start && array[--j] > array[pivot]);
        while(i < end && array[++i] < array[pivot]);
        if (i >= j) break;
        swap(array[i], array[j]);
    }
    swap(array[pivot], array[j]);
    quick_sort_r(array, start, j-1);
    quick_sort_r(array, j+1, end);
}

void quick_sort(vector<int> &array) {
    quick_sort_r(array, 0, array.size()-1);
}

int main() {
    vector<vector<int>> test_cases{{5,1,-5,0,8,4,2,3,4},
                                   {1,4,6,4,11,3,-1,3,0},
                                   {0},
                                   {7,7,7,7,7,7,7,7},
                                   {9,8,7,6,5,4,3,2,1},
                                  };
    for (auto test_case : test_cases) {
        quick_sort(test_case);
        for (auto i : test_case)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}