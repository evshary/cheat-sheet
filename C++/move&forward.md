# move
`std::move` is to turn the object into rvalue. After move constructor or move assignment, the original object will not be able to use.

The difference between move and copy constructor/assignment is whether the object is rvalue. While rvalue use move, or use copy.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class TEST final {
public:
    TEST() {
        cout << "Constructor 1" << endl;
        _len = 0;
        _str = NULL;
    }
    TEST(const char *str) {
        cout << "Constructor 2" << endl;
        copy_str(str);
    }
    ~TEST() {
        cout << "Deconstructor" << endl;
        if (_str) free(_str);
    }
    // copy
    TEST(const TEST& test) {
        cout << "Copy Constructor" << endl;
        copy_str(test._str);
    }
    TEST& operator=(const TEST& test) {
        cout << "Copy Assignment" << endl;
        copy_str(test._str);
        return *this;
    }
    // move: we don't copy but just move ownership
    TEST(TEST&& test) {
        cout << "Move Constructor" << endl;
        _len = test._len;
        _str = test._str;
        test._len = 0;
        test._str = NULL;
    }
    TEST& operator=(TEST&& test) {
        cout << "Move Assignment" << endl;
        if (this == &test) {
            _len = test._len;
            _str = test._str;
            test._len = 0;
            test._str = NULL;
        }
        return *this;
    }
private:
    int _len;
    char *_str;
    void copy_str(const char *str) {
        _len = strlen(str);
        _str = new char[_len+1];
        strcpy(_str, str);
        _str[_len] = 0;
    }
};

int main() {
    const char *s = "FOO";
    TEST test0(s);
    /* If rvalue, use move, or use copy. */
    cout << "----- Call copy assignment -----" << endl;
    TEST test1;
    test1 = test0;
    cout << "----- Call copy constructor -----" << endl;
    TEST test2(test0);
    cout << "----- Call move constructor -----" << endl;
    TEST test3(move(test0));
    cout << "----- Call move assignment -----" << endl;
    TEST test4;
    test4 = move(test0);
    return 0;
}
```

# Perfect Forwarding
`forward` can reserve the property(lvalue, rvalue) of object.
```cpp
#include <iostream>

class TEST final {
public:
    // while object is lvalue
    void callMethod() & {std::cout << "call Method lvalue" << std::endl;}
    // while object is rvalue
    void callMethod() && {std::cout << "call Method rvalue" << std::endl;}
};

#if 1 // we can use forward and template to simplify the code
template<typename T>
void call(T && t){
    // To reserve the properties of test (lvalue or rvalue)
    std::forward<T>(t).callMethod();
}
#else
void call(TEST & test) {
    std::cout << "test is lvalue" << std::endl;
    test.callMethod();
}

void call(TEST && test){
    std::cout << "test is rvalue" << std::endl;
    // To make lvalue become rvalue
    std::move(test).callMethod();
}
#endif

int main() {
    auto test = TEST();
    call(test);
    call(TEST());
    return 0;
}
```