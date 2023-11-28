# vector algorithm

## Basic

* Count the element number in the vector
```c++
#include <algorithm>
cout << count(v.begin(), v.end(), 8) << endl;  // print how many 8 in the vector v
```

* Sort
```c++
#include <algorithm>
// sort from small to big
sort(v.begin, v.end());
// sort from big to small - way1
std::sort(v.rbegin(), v.rend());
// sort from big to small - way2 (After C++14)
std::sort(v.begin(), v.end(), std::greater<>());
// sort from big to small - way3
bool comp(int &num1, int &num2) {
    return num1 > num2;
}
sort(v.begin, v.end(), comp);
```

* reverse the vector
```cpp
#include <algorithm>
std::reverse(v.begin(), v.end());
```

* erase-remove idiom: remove the element from vector
  - `remove` will move the vector after matched element forward (but extra space is still reserved), and `erase` will remove these elements.
```cpp
#include <algorithm>
// What remove can do
vector<int> v{8,3,8,9,1,1};
std::remove(v.begin(), v.end(), 8);  // v_after_remove will be {3,9,1,1,1,1} (The last 2 elements are reserved)
// Remove 8 from vector v
vector<int> v{8,3,8,9,1,1};
v.erase(std::remove(v.begin(), v.end(), 8), v.end());
```

Combine two vectors

```cpp
vector<int> v1{1,2,3};
vector<int> v2{4,5,6};
// become {1,2,3,4,5,6}
v1.insert(v1.end(), v2.begin(), v2.end());
```

## Advanced

* Find max / min number
```c++
#include <algorithm>
vector<int> v{3,2,1,7,8,9};
int max_index = max_element(v.begin(), v.end()) - v.begin();
int max_element = *max_element(v.begin(), v.end());
int min_index = min_element(v.begin(), v.end()) - v.begin();
int min_element = *min_element(v.begin(), v.end());
```

* Find the specific number
```c++
#include <algorithm>
vector<int> v{3,2,1,7,8,9};
auto it = find(v.begin(), v.end(), 7); // it type is vector<int>::iterator
if (it != v.end()) {
    cout << *it << " is at index " << it-v.begin() << endl;
}
```

* upper_bound/lower_bound
  - Only used in sorted array
```c++
#include <algorithm>
vector<int> v{3,5,1,6,2,9,2,2};
sort(v.begin(), v.end());  // 1,2,2,2,3,5,6,9
vector<int>::iterator low, up;
// find the first element >= 2
low = lower_bound(v.begin(), v.end(), 2); // the iterator points to 2nd element
cout << "Low idx will be " << low-v.begin() << endl;  // return idx 1
// find the first element > 2
up = upper_bound(v.begin(), v.end(), 2);  // the iterator points to 5th element
cout << "Up idx will be " << up-v.begin() << endl;  // return idx 4

// if element not exist
low = lower_bound(v.begin(), v.end(), 4); // the iterator points to 5th element
cout << "Low idx will be " << low-v.begin() << endl;  // return idx 5 (v[5] = 5 >= 4)
up = upper_bound(v.begin(), v.end(), 4);  // the iterator points to 5th element
cout << "Up idx will be " << up-v.begin() << endl;  // return idx 5 (v[5] = 5 > 4)
```

* binary_search
```c++
#include <algorithm>
vector<int> v{3,5,1,6,2,9,2,2};
sort(v.begin(), v.end());  // 1,2,2,2,3,5,6,9
if (binary_search(v.begin(), v.end(), 4) == true) {
    cout << "number found" << endl;
} else {
    cout << "not found" << endl;
}
```
