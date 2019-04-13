#include <iostream>
#include <vector>
using namespace std;

void swap(int &num1, int &num2) {
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void bubble_sort(vector<int> &array) {
    int sorted_num = 0;
    for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        bool swap_flag = false;
        for (vector<int>::iterator nit = array.begin()+1; nit != array.end() - sorted_num; nit++) {
            if (*nit < *(nit-1)) {
                swap(*nit, *(nit-1));
                swap_flag = true;
            }
        }
        if (!swap_flag)
            break;
        sorted_num++;
    }
}

int main() {
    vector<int> array{98,88,96,93,65,81,82,29,9,21};
    bubble_sort(array);
    for (auto num : array) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}