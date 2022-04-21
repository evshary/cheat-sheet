#include <iostream>
#include <vector>
using namespace std;

void merge_sort_r(vector<int> &array, vector<int> &tmp_array, int start, int end) {
    if (start == end) return;
    int middle = (start + end)/2;
    merge_sort_r(array, tmp_array, start, middle);
    merge_sort_r(array, tmp_array, middle+1, end);
    int sub_ptr1 = start, sub_ptr2 = middle + 1;
    for (vector<int>::iterator it = tmp_array.begin() + start; it != tmp_array.begin() + end + 1; it++) {
        if (sub_ptr1 <= middle && sub_ptr2 > end) {
            *it = array[sub_ptr1++];
        } else if (sub_ptr1 > middle && sub_ptr2 <= end) {
            *it = array[sub_ptr2++];
        } else {
            if (array[sub_ptr1] <= array[sub_ptr2]) {
                *it = array[sub_ptr1++];
            } else {
                *it = array[sub_ptr2++];
            }
        }
    }
    for (int i = start; i <= end; i++)
        array[i] = tmp_array[i];
}

void merge_sort(vector<int> &array) {
    vector<int> tmp_array(array.size());
    merge_sort_r(array, tmp_array, 0, array.size()-1);
}

int main() {
    vector<int> array{66,62,76,52,74,57,52,38,28,7};
    merge_sort(array);
    for (auto num : array) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}