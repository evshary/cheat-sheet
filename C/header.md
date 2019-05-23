# stdlib.h
* [abs](https://en.cppreference.com/w/c/numeric/math/abs)
```c
int abs(int n);
long labs(long n);
long long llabs(long long n);
// example
abs(-5);  // 5
```
* random: [srand](https://en.cppreference.com/w/c/numeric/random/srand) & [rand](https://en.cppreference.com/w/c/numeric/random/rand)
```c
void srand(unsigned seed);
int rand();
// example
srand(time(0)); // used as seed
rand();
```

# ctypes.h
* alpha: [isalpha](https://en.cppreference.com/w/c/string/byte/isalpha), [isupper](https://en.cppreference.com/w/c/string/byte/isupper), [islower](https://en.cppreference.com/w/c/string/byte/islower)
```c
int isalpha(int ch);
int isupper(int ch);
int islower(int ch);
// example
isalpha('A'); // non zero
isalpha('0'); // 0
isupper('A'); // non zero
isupper('a'); // 0
islower('a'); // non zero
islower('A'); // 0
```
* other: [isdigit](https://en.cppreference.com/w/c/string/byte/isdigit), [isprint](https://en.cppreference.com/w/c/string/byte/isprint)
```c
int isdigit(int ch);
int isprint(int ch);
// example
isdigit('0'); // non zero
isdigit('a'); // 0
isprint('!'); // non zero
isprint(0);   // 0
```

# math.h
* Type-generic macro: [fmax](https://en.cppreference.com/w/c/numeric/math/fmax) & [fmin](https://en.cppreference.com/w/c/numeric/math/fmin)
```c
#define fmax(x,y)
#define fmin(x,y)
fmax(x, y);
fmin(x, y);
// example
fmax(5, 3); // 5
fmin(5, 3); // 3
```
* Type-generic macro: [sqrt](https://en.cppreference.com/w/c/numeric/math/sqrt)
```c
#define sqrt(arg)
sqrt(num);
// example
sqrt(100); // 10
```
* Type-generic macro: [pow](https://en.cppreference.com/w/c/numeric/math/pow)
```c
#define pow(base, exponent)
pow(base, exponent);
// example
pow(2,10); // 1024
```
* Type-generic macro: [floor](https://en.cppreference.com/w/c/numeric/math/floor) & [ceil](https://en.cppreference.com/w/c/numeric/math/ceil)
```c
#define floor(arg)
#define ceil(arg)
floor(num);
ceil(num);
// example
floor(2.5);  // 2
floor(-2.5); // -3
ceil(2.5);   // 3
ceil(-2.5);  // -2
```
* [round](https://en.cppreference.com/w/c/numeric/math/round)
```c
round(num);
// example
round(2.4); // 2
round(2.5); // 3
```

# limits.h
Define the limit value of different types.

* SCHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN
* SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX
* UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX

# stdboo.h
Define bool type and true/false.

# stdio.h
* type: size_t, FILE
* define: NULL, EOF, SEEK_CUR, SEEK_END, SEEK_SET
* file operation
```c
```
* formatted I/O
```c
```

# string.h
