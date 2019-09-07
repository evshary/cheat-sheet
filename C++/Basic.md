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
auto_ptr is deprecated. Use unique_ptr instead.

## Usage
* auto_ptr can help us to manage the memory. Resource is freed while leaving the variable scope.
* auto_ptr is **inline** implementation, so the efficiency isn't affected.
* auto_ptr can't be used to manage dynamic arrays. The result is unpredictable.
* Don't put auto_ptr into STL container since the operation of STL container may affect auto_ptr.
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

# unique_ptr
## Usage
* unique_ptr is developed to replace auto_ptr in C++11.
  - We can't use assignment but need to use move to transfer ownership.
* Use it when we want to ensure single ownership of resource.

## Example
```c++
unique_ptr<int> ptr1(new int(1));
cout << ptr1.get(); // resource's address
// wrong operation
unique_ptr<int> ptr2 = ptr1;
// correct operation
unique_ptr<int> ptr2 = move(ptr1);
cout << ptr1.get(); // Now is zero. 
cout << ptr2.get(); // resource's address
```

# shared_ptr
## Usage
* Allow multiple pointers to the same resource and manage with counters.
* The resource will be released while counter is 0.

## Example
```c++
shared_ptr<int> ptr1(new int(1));
shared_ptr<int> ptr2(ptr1);
// show the same resource's address here.
cout << ptr1.get();
cout << ptr2.get();
// Both show 2 here. (use count)
cout << ptr1.use_count();
cout << ptr2.use_count();
// Reset ptr1 ownership
ptr1.reset();
// Use count becomes 1.
cout << ptr2.use_count();
```

# weak_ptr
## Usage
* weak_ptr is to avoid cyclic dependency. Often used with shared_ptr.

## Example
* The example below cause memory leak.
  - A and B can't be released since they are used by each other.
```c++
class A {
public:
  shared_ptr<B> b;
};

class B {
public:
  shared_ptr<A> a;
};

int main() {
  shared_ptr<A> ptrA(new A);
  shared_ptr<B> ptrB(new B);
  A->b = ptrB;
  B->a = ptrA;
  // ...
}
```
* We can use weak_ptr instead.
```c++
class A {
public:
  weak_ptr<B> b;
};

class B {
public:
  weak_ptr<A> a;
};

int main() {
  shared_ptr<A> ptrA(new A);
  shared_ptr<B> ptrB(new B);
  A->b = ptrB;
  B->a = ptrA;
  // ...
}
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

# string
We need `#include <string>` first.

* Declaration
```c++
string str1;  // empty string
string str2("test123");  // use const string to create
string str3(str2);  // use str2 to create
```
* empty, compare, size
```c++
// Empty or not
if (str1.empty())
  cout << "empty string" << endl;
// Compare
if (str1 == str2)
  cout << "str1 equals to str2" << endl;
// Access
for (int i = 0; i < str1.size(); i++)
  cout << str1[i] << endl;
```
* assign, append, insert, erase
```c++
// get 4 bytes from index 1 of str2 to str1
str1 = str1.assign(str2, 1, 4);
// append 4 bytes from index 1 of str2 to str1
str1 = str1.append(str2, 1, 4);
// insert "test123" from index 4
str1 = str1.insert(4, "test123")
```
* find & string::npos
```c++
string abc = "hello world";
size_t found = abc.found("hello");
if (found != string::npos) // string::npos stands for the end of string
  // do something... and found will be the position of abc
// Continue to find from "found" location
found = abc.find("world", found);
```
* find_first_of: such as strtok in C
```c++
// Replace !@#$ with *
size_t found = str1.find_first_of("!@#$");
while (found != string::npos) {
  str1[found] = '*';
  found=str1.find_first_of("!@#$", found+1);
}
```
* substr
```c++
string str = "abc->efg->hij->";
string delimiter = "->";
size_t pos, last_pos = 0;
string token;
while ((pos = str.find(delimiter, last_pos)) != string::npos) {
  token = str.substr(last_pos, pos-last_pos);
  cout << token << endl;
  last_pos = pos + delimiter.length();
}
```
* string/int conversion
```c++
string val = to_string(256);  // from 256 to string
int val = stoi("256");        // from string to 256
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
