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

# function

Similar with function pointer of C.

Need `#include <functional>`

```cpp
#include <iostream>
#include <functional>

int add(int x, int y) {
    return x+y;
}

int main() {
    // Use global function
    std::function<int(int, int)> myfunc1 = add;
    std::cout << "function result of 1+1: " << myfunc1(1, 1) << std::endl;
    // Use lambda
    std::function<int(int, int)> myfunc2 = [=](int x, int y) -> int {return x + y;};
    std::cout << "lambda result of 1+1: " << myfunc2(1, 1) << std::endl;
    return 0;
}
```

# bind

bind is function wrapper, which can assign specific arguments to the function.

Need `#include <functional>`

```cpp
#include <iostream>
#include <functional>
#include <string>

int add(int x, int y, std::string name) {
    std::cout << "Argument: x=" << x << ", y=" << y << ", name=" << name << std::endl;
    return x+y;
}

int main() {
    // In fact, you can use auto bind_func = std::bind(...) to make it easier
    std::function<int(std::string,int)> bind_func = std::bind(add, std::placeholders::_2, 1, std::placeholders::_1);
    int result = bind_func("myname", 3);
    std::cout << "Result=" << result << std::endl;
    return 0;
}
```
