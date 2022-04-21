#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &array) {
    int tmp;
    vector<int>::iterator nit;
    for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        tmp = *it;
        for (nit = it; nit != array.begin() && tmp < *(nit-1); nit--) {
            *nit = *(nit-1);
        }
        *nit = tmp;
    }
}

int main() {
    vector<int> array{71,3,25,83,27,8,100,40,78,36};
    insertion_sort(array);
    for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}