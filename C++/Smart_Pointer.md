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