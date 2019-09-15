# Basic Usage
Exception can split the logic of algorithm and error handling, and increase the readability.

```c++
int main() {
  try {
    throw 1; // Throw int error
  } catch (int e) {
    cout << "e=" << e << endl;
  } catch (char *s) {
    cout << "s=" << s << endl;
  } catch (...) {
    cout << "Catch all the error not int or char" << endl;
  }
  return 0;
}
```

# Define own exception
We can also create our own exception class.

```c++
class Exception {
public:
  Exception(int e) {
    _msg = "Error " + to_string(e);
  }
  string msg() {
    return _msg;
  }
private:
  string _msg;
};
int main() {
  try {
    throw Exception(1);
  } catch(Exception e) {
    cout << e.msg() << endl;
  }
}
```

# Standard exception
We should `#include <exception>` first. Reference [here](http://www.cplusplus.com/reference/exception/exception/).

```c++
#include <exception>
class OBJ {virtual void func();};                                                                     
int main() {
  try {
    OBJ *obj = nullptr;
    typeid(*obj);
  } catch(exception& e) {
    cout << "Catch: " << e.what() << endl;
  }
  return 0;
} 
```