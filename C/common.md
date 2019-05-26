# [union](https://en.cppreference.com/w/c/language/union)
* The size is decided by the largest member
```c
union VAR {
    char ch;
    short sh;
    int num;
};
union VAR var;
```
* typedef
  - separation
```c
union _VAR {
    char ch;
    short sh;
    int num;
} VAR;
typedef union _VAR VAR;
VAR var;
```
  - combination
```c
typedef union _VAR {
    char ch;
    short sh;
    int num;
} VAR;
VAR var;
```

# [structure](https://en.cppreference.com/w/c/language/struct)
* normal declare
```c
struct OBJ {
    int member1;
    int member2;
    char member3;
};
struct OBJ obj;
```
* use typedef
  - separation
```c
struct _OBJ {
    int member1;
    int member2;
    char member3;
};
typedef struct _OBJ OBJ;
OBJ obj;
```
  - combination
```c
typedef struct _OBJ {
    int member1;
    int member2;
    char member3;
} OBJ;
OBJ obj;
```
* Init
  - Normal
```
OBJ obj = {1,2,'3'};
```
  - Without order
```c
OBJ obj = {
  .member2 = 2;
  .member1 = 1;
  .member3 = '3';
};
```
  - Array
```c
OBJ objs[3] = {
  [0] = {
    .member2 = 20;
    .member1 = 10;
    .member3 = '0';
  },
  [2] = {
    .member2 = 22;
    .member1 = 12;
    .member3 = '2';
  },
};
```
  - Nested
```c
struct OBJ {
    int member1;
    struct TEST {
      int test;
      int abc;
    };
};
struct OBJ obj = {
    0,
    {1,2}
}
```

# [enum](https://en.cppreference.com/w/c/language/enum)
* normal declare
```c
enum NUMBER {
    ONE = 1,  // 1
    TWO,      // 2
    THREE     // 3
};
enum NUMBER number;
```
* use typedef
  - separation
```c
enum _NUMBER {
    ONE = 1,  // 1
    TWO,      // 2
    THREE     // 3
};
typedef enum _NUMBER NUMBER;
NUMBER number;
```
  - combination
```c
typedef enum _NUMBER {
    ONE = 1,  // 1
    TWO,      // 2
    THREE     // 3
} NUMBER;
NUMBER number;
```

# [MACRO](https://en.cppreference.com/w/c/preprocessor)
* condition
  - `#if`, `#ifdef`, `#ifndef`, `#elif`, `#else`, `#end`
* source file
  - `#include`
* error
  - `#error`: show error message to developers
```c
#ifndef XXXX
#  error "You should define XXX"
#endif
```
* replace
  - `#define`, `#undef`
  - reserved MACRO: `__FILE__`, `__LINE__`, `__DATE__`, `__TIME__`
* command
  - `#pragma`: tell compiler to do something
```c
// Ensure the file should be only included once
#pragma once
```
## Other usage
* Use `do{}while(0)`
  - prevent dangling else
  - Able to jump out of the loop.
```c
#define TEST_FUNC(VAR) \
do { \
  VAR *= 2; \
  VAR++; \
} while(0);

if (var == 1)
  // do something
else
  TEST_FUNC(var); // dangling else
```
* Use () in define to prevent error
```c
// error when ADD(1,2) * ADD(2,3) => 1+2 * 2+3
#define ADD(a,b) a+b
// correct
#define ADD(a,b) (a+b)
```
* Transform str to "str"
```c
#define STR(exp) #exp
// print "abc123"
printf("%s\n", STR(abc123));
```
* concatenate
  - example is from [here](https://github.com/embedded2016/raytracing/blob/master/objects.h).
```c
#define DECLARE_OBJECT(name) \
	struct __##name##_node; \
	typedef struct __##name##_node *name##_node; \
	struct __##name##_node { \
	name element; \
	name##_node next; \
	}; \
	void append_##name(const name *X, name##_node *list); \
	void delete_##name##_list(name##_node *list);

DECLARE_OBJECT(light)
DECLARE_OBJECT(rectangular)
DECLARE_OBJECT(sphere)
```
* double MACRO
```c
// wrong way
#define STR(s) #s

void func1 {
  printf("%s", STR(INT_MAX));  // print "INT_MAX"
}
// other way
#define _STR(s) #s
#define STR(s) _STR(s)

void func2 {
  printf("%s", STR(INT_MAX)); // print "0x7fffffff"
}
```
* variable length argument
```c
#define DEBUG(...) printf(__VA_ARGS__)
// WRONG: The below will become printf("abc",) while DEBUG("abc") (There is no other arguemnt)
#define DEBUG(format, ...) printf(format, __VA_ARGS__)
// RIGHT: We should use this
#define DEBUG(format, ...) printf(format, ##__VA_ARGS__)
```
* generic type
  - `_Generic`
```c
void int_func(int i) {
  // do something
}
void char_func(char c) {
  // do something
}
void default_func(double d){
  // do something
}
#define func(T) \
    _Generic((T), \
        int: int_func, \
        char: char_func, \
        default: default_func \
    )(T)

...
func(100);
func('s');
func(1.5);
...
```
* Check OS
```c
#if defined(_WIN32)
  // This is win32 or win64
#elif defined(_WIN64)
  // This is win64
#elif defined(__linux__)
  // This is Linux
#elif defined(__unix__)
  // This is Unix
#elif defined(__APPLE__)
  // This is MACOS
#else
  // This is other OS
#endif
```

# variadic functions
* Declare variadic functions
```c
void func(int arg1, ...)
{
  va_list args;
  // First arguemnt is arg1
  va_start(args, arg1);
  // The second argument is int
  va_arg(ap, int);
  // The third argument is int
  va_arg(ap, char);
  va_end(args);
}
```
* Use format for variadic functions
```c
void parse_format(const char *format, ...)
{
  va_list args;
  char buf[100];
  va_start(args, format);
  // parse format and put into the buffer
  vsnprintf(buf, sizeof(buf), format, args); // include in stdio.h
  va_end(args);
  // Do something with the buf
}
```

# file operation
* read file
```c
char buf[255];
char ch;
FILE* fp = fopen("abc.txt", "r");
if(!fp) return -1;
// read bytes
ch = fgetc(fp);
// read n bytes or until EOF
fgets(buf, 255, (FILE*)fp);
// format read or until space
fscanf(fp, "%s", buf);
if (feof(fp))
  printf("Successfully read.");
fclose(fp);
```
* write file
```c
FILE* fp = fopen("abc.txt", "w");
// format print
fprintf(fp, "TEST TEST\n");
// print
fputs("This is testing for fputs...\n", fp);
// Sync with actual file (not necessary)
fflush(fp);
fclose(fp);
```
* get / move position
```c
FILE* fp = fopen("abc.txt", "w");
// Get the current position
int pos = ftell(fp);
// Move the pointer to 10th bytes from the beginning of the file.
fseek(fp, 10, SEEK_SET);
// Move the pointer backward 5 bytes from the current position
fseek(fp, -5, SEEK_CUR);
// Move the pointer backward 5 bytes from the end of the file.
fseek(fp, -5, SEEK_END);
fclose(fp);
```

# time
* calculate the execution time
```c
clock_t start = clock();
// do something
clock_t end = clock();
double time_used = ((double)end - (double)start) / CLOCKS_PER_SEC;
printf("It took %f seconds\n", time_used);
```
* compare the time (int type of struct tm or time_t)
```c
time_t now = time(NULL);
struct tm past_tm = {
    .tm_year = 109,
    .tm_mon = 0,
    .tm_mday = 1,
    .tm_hour = 0,
    .tm_min = 0,
    .tm_sec = 0
};
time_t past = mktime(&past_tm)
double sec = difftime(now, past);
printf("From 2019.01.01 00:00:00 to now, it elapses %f seconds\n", sec);
```
* Calculate the 20 months ago
```c
char buf[100];
time_t now = time(NULL);
struct tm now_tm = *localtime(&now);
if (!strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M:%S", &now_tm))
    return -1;
printf("current is %s\n", buf);
now_tm.tm_mon -= 20;
mktime(&now_tm); // update now_tm
if (!strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M:%S", &now_tm))
    return -1;
printf("20 months ago is %s\n", buf);
```
* Print the format
```c
char buf[100];
time_t now = time(NULL);
struct tm now_tm = *localtime(&now);
if (!strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M:%S", &now_tm))
    return -1;
printf("Date representation from struct tm is %s\n", buf);
time_t time_repr = mktime(&now_tm);
printf("Date representation from time_t is %s\n", ctime(time_repr));
```

# random
* Generate random (from 0 to 999)
```c
int ran;
srand(time(NULL));
ran = rand()%1000; // from 0 to 999
```

# transform string to integer
* Transform long
```c
// Without checking the result
char *ptr1 = "0x1234";
long value1 = strtol(ptr1, NULL, 16);
// Checking the result
char *ptr2 = "1234";
char *end;
long value2 = strtol(ptr2, end, 10);
if (errno == ERANGE) printf("out or range\n");
if (end == ptr2) printf("Unable to convert\n"); 
```
* Transform a list of long
```c
char *ptr = "40 -20 900000000000000000000000000000 abc";
char *end;
for (long i = strtol(p, &end, 10); p != end; i = strtol(p, &end, 10))
{
    printf("Parse string: %.*s", (int)(end-p), p);
    if (errno == ERANGE) {
        // out of range
        errno = 0;
    }
    p = end;
    printf("%ld\n", i);
}
```
# sort
```c
int compare_func(const void* arg1, const void* arg2) {
  // return <0 : arg1<arg2 
  //        =0 : arg1=arg2
  //        >0 : arg1>arg2
  return (*(int *)arg1 - *(int *)arg2);
}
int nums = {10, 5, 7, 3, 8};
qsort(nums, sizeof(nums)/sizeof(int), sizeof(int), compare_func);
// 3,5,7,8,10
```
# binary search
```c
int compare_func(const void* arg1, const void* arg2) {
  return (*(int *)arg1 - *(int *)arg2);
}
int nums = {3, 5, 7, 8, 10};
int target = 5;
int *found = bsearch(&target, nums, sizeof(nums)/sizeof(int), sizeof(int), compare_func);
if (found == NULL)
   printf("Not found\n");
else
    printf("Found %d\n", *found);
```

# string operation
* split string with delimiter
```c
char buf[] = "abc efg hij klm,kkk,eee,ddd";
char *token = strtok(buf, " ,");
while(token) {
  // Do something.
  strtok(NULL, " ");
}
```