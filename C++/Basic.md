# new/delete
Use `new` to allocate space and `delete` to free.

```c++
// normal
int *ptr = new int(1);
delete ptr
// array
int *arr = new int[5];
delete [] arr;
```

# auto_ptr
## Usage
* auto_ptr can help us to manage the memory. Resource is freed while leaving the variable scope.
* auto_ptr is **inline** implementation, so the efficiency isn't affected.
* auto_ptr can't be used to manage dynamic arrays. The result is unpredictable.
* Don't put auto_ptr into container since the operation of container may affect auto_ptr.
* Don't use multiple auto_ptr to the same address since it may cause multiple free.

## Example
* Declare and release
```c++
#include <memory>
// declare
auto_ptr<int> int_ptr(new int(1234));
auto_ptr<OBJ_NAME> ptr2(ptr1);
// release
int_ptr.release();
```
* Check the auto_ptr is valid or not
```c++
auto_ptr<int> int_ptr;
if(int_ptr.get() == 0) {
  int_ptr.reset(new int(5678));
}
```
* Transfer the responsibility of free.
```c++
// transfer the responsibility of free from ptr1 to ptr2
auto_ptr<int> ptr1(new int(1));
auto_ptr<int> ptr2(new int(2));
ptr2 = ptr1;
```

# default value for function argument
```c++
int func(int, int = 1);

int main() {
    func(1);    // 1
    func(1, 2);  // 2
    return 0;
}

int func(int num, int times) {
    return num * times;
}
```

# reference
* Reference means an alias of the variable or object. It can change the value of target.
* **WARNING: reference should be initialized.**
* Basic
```c++
int var = 123;
int &ref = var;
```
* Add const while refer to const value
```c++
const int &ref = 123;
```
* Refer to pointer
```c++
int var = 123;
int *ptr = &var;
int *&ref = ptr;
```

# algorithm
To use algorithm, we need `#include <algorithm>` first.

* sort
```c++
bool compare_func(int a, int b) {
  // We can only use <, not <=, and we can't change the argument
  return a < b;
}
//...
vector<int> v{3,5,1,6,2,9};
// from small to big
sort(v.begin(), v.end());
sort(v.begin(), v.end(), compare_func);
// from big to small
sort(v.rbegin(), v.rend());
```
* find
```c++
int search = 4;
vector<int>::iterator it = find(v.begin(), v.end(), search);
if (it != ivector.end())
  cout << "Found!" << endl;
else
  cout << "Not found!" << endl;
```
* reverse
```c++
reverse(v.begin(), v.end());
```
* upper_bound/lower_bound
  - Only used in sorted array
```c++
vector<int> v{3,5,1,6,2,9,2,2};
sort(v.begin(), v.end());  // 1,2,2,2,3,5,6,9
vector<int>::iterator low, up;
// find the first element >= 2
low = lower_bound (v.begin(), v.end(), 2); // the iterator points to 1st element
// find the first element > 2
up = upper_bound (v.begin(), v.end(), 2);  // the iterator points to 4th element
```
* max_element, min_element
```c++
vector<int> v{3,5,1,6,2,9};
// find max element
cout<< *max_element(v.begin(), v.end()) << endl;
// find min element
cout<< *min_element(v.begin(), v.end()) << endl;
```
