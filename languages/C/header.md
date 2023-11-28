# header
There are total 29 headers in C11. However there are 82 headers in POSIX 2008, including the headers in C99.

Some headers, like `arpa/inet.h` or `sys/socket.h`, are only defined in POSIX 2008, not C11.

You can refer to [the answer](https://stackoverflow.com/questions/2027991/list-of-standard-header-files-in-c-and-c) in stack overflow.

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
* [memory](https://en.cppreference.com/w/c/memory)
```c
void* malloc(size_t size);
void* calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t new_size);
void free(void* ptr);
void *aligned_alloc(size_t alignment, size_t size);
// example
int *ptr = malloc(5 * sizeof(int));
obj *ptr = calloc(5, sizeof(obj));  // alloc 5 object and init the storage to 0
int *ptr = realloc(ptr, 10 * sizeof(int));  // reallocate ptr as 10 * sizeof(int)
int *ptr aligned_alloc(1024, 1024 * sizeof(int)); // malloc memory with 1024 bytes alignment
```
* [qsort](https://en.cppreference.com/w/c/algorithm/qsort)
```c
void qsort(void *ptr, size_t count, size_t size,
           int (*comp)(const void *, const void *));
```
* [bsearch](https://en.cppreference.com/w/c/algorithm/bsearch)
```c
void* bsearch(const void *key, const void *ptr, size_t count, size_t size,
              int (*comp)(const void*, const void*));
```
* type conversion
```c
double atof(const char* str);
int atoi( const char *str);
long atol(const char *str);
long long atoll(const char *str);
long strtol(const char *restrict str, char **restrict str_end, int base);
unsigned long strtoul(const char *restrict str, char **restrict str_end, int base);
float strtof(const char *restrict str, char **restrict str_end);
double strtod(const char *restrict str, char **restrict str_end);
// example
atoi(" 123abc"); // 123
atoi("abc");     // 0
atoi("0");       // 0
char *end;
char *ptr = "123 456";
strtol(ptr, &end, 10);  // 123
ptr = end;
strtol(ptr, &end, 10);  // 456
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

# stdbool.h
Define bool type and true/false.

# stdio.h
* type: size_t, FILE
* define: NULL, EOF, SEEK_CUR, SEEK_END, SEEK_SET
* [file operation](https://en.cppreference.com/w/c/io)
```c
FILE *fopen(const char *restrict filename, const char *restrict mode);  // not thread-safe
int fclose(FILE *stream);
int fflush(FILE *stream);  // synchronize with actual file
int fscanf( FILE *restrict stream, const char *restrict format, ... );
int fprintf( FILE *restrict stream, const char *restrict format, ... );
long ftell( FILE *stream );
int fseek(FILE *stream, long offset, int origin);
```
* formatted I/O
```c
// parse the string
int scanf( const char *restrict format, ... );​
int sscanf( const char *restrict buffer, const char *restrict format, ... );
// output the format string
​int printf( const char *restrict format, ... );​
int sprintf( char *restrict buffer, const char *restrict format, ... );
int snprintf( char *restrict buffer, size_t bufsz, 
              const char *restrict format, ... );
```

# time.h
* type: [struct tm](https://en.cppreference.com/w/c/chrono/tm), [time_t](https://en.cppreference.com/w/c/chrono/time_t), [clock_t](https://en.cppreference.com/w/c/chrono/clock_t)
  - time_t: seconds from 1970/1/1 00:00 UTC.
  - clock_t: the unit is defined by every processor, ablt to be used with CLOCKS_PER_SEC.
```c
struct tm {
  int tm_sec;   // 0-59, 60 for leap second
  int tm_min;   // 0-59
  int tm_hour;  // 0-23
  int tm_mday;  // days of the month, 1-31
  int tm_mon;   // months since Jan, 0-11
  int tm_year;  // years from 1900
  int tm_wday;  // days from Sunday, 0-6
  int tm_yday;  // days from Jan 1, 0-365
  int tm_isdst; // Daylight Saving Time flag
};
```
* time manipulation: [difftime](https://en.cppreference.com/w/c/chrono/difftime), [time](https://en.cppreference.com/w/c/chrono/time), [clock](https://en.cppreference.com/w/c/chrono/clock)
```c
// time_end - time_beg
double difftime(time_t time_end, time_t time_beg);
time_t time(time_t *arg);
clock_t clock(void);
```
* format conversion
```c
// from time_t to struct tm
struct tm *gmtime(const time_t *time);  // not thread-safe
struct tm *localtime(const time_t *time);  // not thread-safe
// from struct tm to time_t
time_t mktime(struct tm *time);
// from time_t to char*
char* ctime(const time_t* time); // not thread-safe
// from struct tm to char*
size_t strftime(char *restrict str, size_t count, 
                const char *restrict format, const struct tm *restrict time);
```

# stdarg.h
* [variadic functions](https://en.cppreference.com/w/c/variadic)
```c
void va_start(va_list ap, parm_n);
T va_arg(va_list ap, T);
void va_end(va_list ap);
```

# string.h
* string manipulation
```c
char *strcpy(char *restrict dest, const char *restrict src);
char *strncpy(char *restrict dest, const char *restrict src, size_t count);
// copy src to the end of dst
char *strcat(char *restrict dest, const char *restrict src);
// copy src to the end of dst with maximum count bytes.
char *strncat(char *restrict dest, const char *restrict src, size_t count);
```
* string examination
```c
size_t strlen(const char *str);
int strcmp(const char *lhs, const char *rhs);
int strncmp(const char *lhs, const char *rhs, size_t count);
// return the pointer to the first ch occurs
char *strchr(const char *str, int ch);
// return the pointer to the first substr occurs
char *strstr(const char* str, const char* substr);
// split the string with delim
char *strtok(char *restrict str, const char *restrict delim);  // not thread safe
```
* char array manipulation
```c
int memcmp(const void* lhs, const void* rhs, size_t count);
void *memset(void *dest, int ch, size_t count);
void* memcpy(void *restrict dest, const void *restrict src, size_t count);
// Similar with memcpy but able to handle the overlapping case
void* memmove(void* dest, const void* src, size_t count);
```