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
Placement new: Create object on specific memory, e.g. stack

```c++
// buffer on stack 
unsigned char buf[10];
// placement new
OBJ *obj = new (buf) OBJ();
// Do something....
// Explicit call for destructor
obj->~OBJ();
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

# enum
* WARNING: We can't increase enum in C++.
  - However if we want to implement FSM, overloading operator++ of the class is a good idea.
```c++
enum NUM {
  ZERO = 0,
  FIRST,
  TWO
};

NUM num = ZERO; // ok
NUM num1 = 0; // error
NUM num2 = ZERO + 1; // error
NUM num3 = num++; // error
cout << num+1 << endl; // ok
```

# union
* The data member of union is using the same space.
* Default member visibility is public, but private and protected are also available.
* We can declare constructor, deconstructor or member function.
```c++
union VALUE {
public: // default is public
  char c;
  int i;
  double d;
  VALUE() {}
  VALUE(char v) {c = v;}
  VALUE(int v) {i= v;}
  VALUE(double v) {d = v;}
};
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

# cast
## static_cast
Change the type directly without checking while runtime.

```c++
int v1 = 1234;
long v2 = static_cast<long>(v1);
char v3 = static_cast<char>(v1);  // with data loss
```

However it may be dangerous while downcasting. We should check it carefully.

```c++
class Base {...};
class Derived : Base {...};
...
// We don't know whether base can be transformed into Derived or not.
if (typeid(*base) == typeid(Derived)) {
  Derived *d = static_cast<Derived *>(base);
}
```

## reinterpret_cast
static_cast can't do the following transformation.

```c++
int v1 = 1234;
int *v2 = &v1;
// transfrom from value to pointer
int *v3 = static_cast<int *>(v1);
// tranform between two different pointer
char *v4 = static_cast<char *>(v2);
```

We can use reinterpret_cast instead.

```c++
int *v3 = reinterpret_cast<int *>(v1);
// tranform between two different pointer
char *v4 = reinterpret_cast<char *>(v2);
```

## dynamic_cast
Able to do safe downcasting.

```c++
class Base {...};
class Derived : Base {...};
...
Derived *d;
if (d = dynamic_cast<Derived *>(base)) {
  // return 0 while dynamic_cast error
}
```

## const_cast
Used to add/remove const and volatile of variable.

```c++
// If v1 is const, the operation will be undefined.
int v1 = 1;
const int *v2 = &v1;
int *v3 = const_cast<int *>(v2);
*v3 = 2; // v1 will become 2.
```

const_cast can be used to pass const variable to function without non-const parameter.

```c++
void func(int *v) {
  cout << *v << endl;
}
...
const int v = 5;
// compile error with the following line.
// func(&v));
func(const_cast<int *>(&v));
```
