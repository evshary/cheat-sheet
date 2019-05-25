# union

# structure

# MACRO

# variable-argument

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