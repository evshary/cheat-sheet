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

## Inheritance
### protected,private inheritance
* Child can inherit parents with 3 ways: public, protected, private

| - | pulbic(orig.) | protected(orig.) | private(orig.) |
| --- | --- | --- | --- |
| public inheritance | public->public | protected->protected | - |
| protected inheritance | public->protected | protected->protected | - |
| private inheritance | public->private | protected->private | - |

```c++
class PARENT {
public:
  void func() {
    cout << "PARENT" << endl;
  }
};
class CHILD : public PARENT {
public:
  void func() {
    this->PARENT::func();
    cout << "CHILD" << endl;
  }
};
int main() {
  CHILD c;
  c.func(); // output: PARENT CHILD
  return 0;
}
```

### The order of constructor & deconstructor
```c++
class A {
public:
  A() {cout << "A" << endl;}
  ~A() {cout << "~A" << endl;}
};
class B {
public:
  B() {cout << "B" << endl;}
  ~B() {cout << "~B" << endl;}
};
class C : public A, public B {
public:
  C() {cout << "C" << endl;}
  ~C() {cout << "~C" << endl;}
};
int main () {
  C c;  // order: A, B, C, ~C, ~B, ~A
  return 0;
}
```

### Virtual Inheritance
* Virtual Inheritance is to avoid duplicate base class.

```c++
class GrandParents {};
// Avoid duplicate GrandParents
class Parents1 : virtual public GrandParents {};
class Parents2 : virtual public GrandParents {};
class Child : public Parents1, public Parents2 {};
```

## Override & Virtual function
* Override is "Early binding" or "Static binding".
* Virtual function is "Late binding" or "Dynamic binding".

```c++
class PARENT {
public:
  virtual void func1() {
    cout << "PARENT virtual" << endl;
  }
  void func2() {
    cout << "PARENT not virtual" << endl;
  }
};
class CHILD : public PARENT {
public:
  void func1() {
    cout << "CHILD virtual" << endl;
  }
  void func2() {
    cout << "CHILD not virtual" << endl;
  }
};
int main() {
  CHILD c;
  PARENT *p = &c;
  c.func1(); // output: CHILD virtual
  p->func1(); // output: CHILD virtual
  c.func2(); // output: CHILD not virtual 
  p->func2(); // output: PARENT not virtual
  return 0;
}
```

## Absract class
* The class with pure virtual function is called abstract class.
  - Pure virtual function should be always defined by subclass.

```c++
class PARENT {
public:
  virtual void func() = 0; // pure virtual function
};
class CHILD {
  void func() {cout << "CHILD" << endl;}
};
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
