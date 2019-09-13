# object
## Usage
* class declaration
```c++
class OBJ {
public:
  // constructor
  OBJ();
  OBJ(int val);
  // deconstructor
  ~OBJ();

  int func();

private:
  int num;
}
```
* Detail fucntion for class
```c++
OBJ::OBJ() {
  num = 1;
}
OBJ::OBJ(int val) {
  num = val;
}
int OBJ::func() {
  cout << num << endl;;
}
```
* Object declaration
```c++
OBJ *obj = new(123);
OBJ obj(456);
OBJ obj = OBJ(789);
```

## const & mutable
* const object can only access const members, while non const object doesn't have the limitation.
* const function member can't modify the data member, except mutable one.

```c++
class OBJ {
public:
  OBJ(int val) {num1 = num2 = val;}
  void func_c(void) const {
    //num1++; // Unable to modify const one
    num2++; // Able to modify mutable one
    cout << num1 << " " << num2 << endl;
  }
  void func(void) {
    num1++;
    num2++;
    cout << num1 << " " << num2 << endl;
  }
private:
  int num1;
  mutable int num2;
};

int main() {
  OBJ obj1(0);
  const OBJ obj2(0);
  obj1.func_c();  // 0 1
  obj1.func();    // 1 2
  obj2.func_c();  // 0 1
  //obj2.func();  // Unable to call non const function member
  return 0;
}
```

## Copy Constructor
* When the member of object is malloced, it may cause memory access error while copy the object.
  - We should redefine the copy constructor.

```c++
class OBJ {
public:
  OBJ(int len) {
    arr = new int[len];
    length = len;
  }
  ~OBJ() {
    delete [] arr;
  }
  // copy constructor
  OBJ(const OBJ& obj) : length(obj.length) {
    arr = new int[length];
    for (int i = 0; i < length; i++) arr[i] = obj.arr[i];
  }
private:
  int *arr;
  int length;
};
// ...
OBJ obj1(5);
OBJ obj2 = obj1; 
```

## Operator overloading
```c++
class OBJ {
public:
  OBJ(int n);
  OBJ operator+(const OBJ&); // overload +
  OBJ& operator++(); // overload ++obj 
  OBJ operator++(int); // overload obj++ 
  // If we use global friend function, we should add one more parameter
  friend OBJ operator*(const OBJ&, const OBJ&); // overload * 
  // friend OBJ operator++(OBJ&); // overload ++obj
  // friend OBJ operator++(OBJ&, int); // overload obj++
  friend ostream& operator<<(ostream&, const OBJ&); // overload <<

private:
  int num;
};

OBJ::OBJ(int n) {
  num = n;
}

OBJ OBJ::operator+(const OBJ& obj) {
  OBJ tmp(this->num + obj.num);
  return tmp;
}

OBJ& OBJ::operator++() {
  this->num++;
  return *this;
} 

OBJ OBJ::operator++(int) {
  OBJ tmp(this->num);
  this->num++;
  return tmp;
}

OBJ operator*(const OBJ& obj1, const OBJ& obj2) {
  OBJ obj(obj1.num * obj2.num);
  return obj;
}

ostream& operator<<(ostream& out, const OBJ& obj) {
  out << "num:" << obj.num;
  return out;
}
```

## User-Defined Conversion
* We can define how to work while convert to other type.

```c++
class OBJ {
public:
  OBJ(int v) {num = v;}
  // Define how it works while OBJ tranform into int.
  operator int() {return num;}
private:
  int num;
};
//...
OBJ obj(123);
cout << obj + 1 << endl;
```

# RTTI
RTTI stands for **Run-Time Type Information**. Able to get object ID while runtime.

Remember to `#include <typeinfo>` first.

```c++
#include <typeinfo> 

class PARENT {
public:
  virtual void func() { cout << "BASE" << endl; }
};
class CHILD1 : public PARENT{
public:
  void func() { cout << "CHILD1" << endl; }
};
class CHILD2 : public PARENT{
public:
  void func() { cout << "CHILD2" << endl; }
};
int main() {
  PARENT *ptr;
  CHILD1 c1;
  CHILD2 c2;
  ptr = &c1;
  cout << typeid(*ptr).name() << endl;
  ptr = &c2;
  cout << typeid(*ptr).name() << endl;
  return 0;
}
```

# struct
* The difference between struct and  is the visibility of member.
  - struct is public in default while class is private.
* How to choose struct or class is based on convention.
  - Used as interface (Data memeber can be accessed by others) => use struct.
  - Dependency in data member (Data member should not be modified directly) => use class.

```c++
struct DERIVED {
  DERIVED(int v) {member = v;}
  void show() {cout << member << endl;}
  int member;
};
// ...
// DERIVED d or struct DERIVED d are both OK.
DERIVED d(123);
d.show();
```

# namespace
We can use namespace to avoid symbol confliction.

* Declare namespace in `test.h`
```c++
namespace test {
  int i = 1;
  void func() {
    cout << "func" << endl;
  }
};
```
* While other file want to use:
```c++
#include "test.h"

int main() {
  cout << test::i << endl;
  test::func();
}
```
* We can use total namespace:
```c++
#include "test.h"
using namespace test;

int main() {
  cout << i << endl;
  func();
}
```

# template
* function template
```c++
template <typename T>
T T_ADD(T a, T b) {
  return a + b;
}
```
* class template
```c++
template <typename T>
class T_CLASS {
  T add(T a, T b) {
    return a + b;
  }
};
int main() {
  T_CLASS<int>  a, b;
  T_CLASS<double> x, y;
}
```
* partial specialization
```c++
// general
template <typename T1, typename T2>
class T_CLASS {
  void print(T1 t1, T2 t2) {
    cout << t1 << endl;
    cout << t2 << endl;
  }
};
// special
template <typename T1>
class T_CLASS<T1, int> {
  void print(T1 t1, int val) {
    cout << t1 << endl;
  }
};
// special with no T
template <>
class T_CLASS<int, int> {
  void print(int val1, int val2) {
    cout << "val=" << val1 + val2 << endl;
  }
};
```

# Lambda
Lambda is an anonymous inline function. It help us: 

1. Make code more concise.
2. Able to access the variable in current scope.

* Normal function
```c++
int func(char val) {
  cout << val << endl;
  return 0;
}
```
* Lambda expression
```c++
auto func = [](char val) -> int {
  cout << val << endl;
  return 0;
};
```

Notice that [] means lambda-introducer(capture clause). We can define which variables in the scope we want to use capture

* `[]`: Don't capture
* `[=]`: Capture all the variable by value.
* `[&]`: Capture all the variable by reference.
* `[v1, &v2]`: v1 by value, v2 by reference.
* `[=, v]`: v by value, and the remains by reference
* `[&, v]`: v by reference, and the remains by value.