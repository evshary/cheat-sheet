# Basic
You can read [cppreference.com](https://en.cppreference.com/w/c/language) for further detail.

Refer to [The C99 standard draft](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) and [The C11 standard draft](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1548.pdf) for standard definition.

# [storage-class specifiers](https://en.cppreference.com/w/c/language/storage_duration)
* auto(default):
  - The storage is allocated when entering the block and deallocated while leaving the block.
* register:
  - Hints the compiler to store the value in register if possible. (Not always take effect)
  - Can't be used as arguments to address-of operator.
* static:
  - The storage duration is the entire execution of the program.
  - In file scope, static variable and function can only be used in the file.
  - In block scope, static variable only inits once.
* extern:
  - To use the variable/function from other file, declare with extern.
* No storage-class specifiers
  - extern for all functions
  - extern for objects at file scope
  - auto for objects at block scope

| storage-class specifiers | description |
| --- | --- |
| auto | automatic duration and no linkage |
| register | automatic duration and no linkage; address of this variable cannot be taken |
| static | static duration and internal linkage (unless at block scope) |
| extern | static duration and external linkage (unless already declared internal) |

# [volatile](https://en.cppreference.com/w/c/language/volatile)
* Tell the compiler the variable may be changed by external function, so we should get the value everytime.
* There are 3 cases to use "volatile":
  - Pointer to memory-mapped I/O
  - The global variable used by ISR.
  - The variable used by several multithread function.
* Example:
```c
volatile int num = 0;
...
while (num == 0); // waiting for other thread to change the value.
```

# [restrict](https://en.cppreference.com/w/c/language/restrict)
* Only **pointers** to object types can be restrict-qualified.
* restrict can be used to tell the compiler that there is no pointer aliasing, and we can do optimization.
  - That is, the restrict-qualified pointer is the only one which can change the memory it points to.
  - It's an important way to improve the performance.
* Example1: compiler can assume the func parameter a != b, and no need to reaccess the value in `return *a + *b`
```c
int func(int *restrict a, int *restrict b) {
    *a = 5;
    *b = 6;
    return *a + *b;
}
```
* Example2: The restrict-qualified pointer in functiuon parameter should never overlap.
```c
void func(int * restrict a, int * const b, int num) {
    for (int i = 0; i < num; i++)
       a[i] += b[i] + i;
}
int nums[20] = {0};
func(nums, nums+5, 10); // undefined behavior
```

# [The right-left rule](http://cseweb.ucsd.edu/~ricko/rt_lt.rule.html)
