#include <iostream>
#include <vector>
using namespace std;

void swap(int &num1, int &num2) {
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void selection_sort(vector<int> &array) {
    for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        vector<int>::iterator min_it = it;
        for (vector<int>::iterator nit = it; nit != array.end(); nit++) {
            if (*nit < *min_it)
                min_it = nit;
        }
        swap(*it, *min_it);
    }
}

int main() {
    vector<int> array{31,58,98,28,70,13,79,47,52,14};
    selection_sort(array);
    for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}