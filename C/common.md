# union

# structure

# file operation

# variable-argument

# random

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

# MACRO