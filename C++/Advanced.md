# object
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
template <class T>
T T_ADD(T a, T b) {
  return a + b;
}
```
* class template
```c++
template <class T>
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
template <class T1, class T2>
class T_CLASS {
  void print(T1 t1, T2 t2) {
    cout << t1 << endl;
    cout << t2 << endl;
  }
};
// special
template <class T1>
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