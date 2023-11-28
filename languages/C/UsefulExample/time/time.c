#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now_time;
    // get current raw time (seconds from 1970.01.01 UTC)
    time(&now_time);
    printf("time(): %ld\n", now_time);
    // print time with string type (local timezone)
    // time_t => string
    printf("ctime: %s", ctime(&now_time));

    // Customized the datetime string type (UTC)
    // time_t => struct tm
    struct tm *now_tm_utc = gmtime(&now_time);
    printf("gmtime(UTC): %d/%d/%d %d:%d:%d\n", (1900+now_tm_utc->tm_year),
                                               (1+now_tm_utc->tm_mon),
                                               (now_tm_utc->tm_mday),
                                               now_tm_utc->tm_hour,
                                               now_tm_utc->tm_min,
                                               now_tm_utc->tm_sec);
    // Customized the datetime string type (local timezone)
    // time_t => struct tm
    struct tm *now_tm_local = localtime(&now_time);
    printf("localtime(local): %d/%d/%d %d:%d:%d\n", (1900+now_tm_local->tm_year),
                                                    (1+now_tm_local->tm_mon),
                                                    (now_tm_local->tm_mday),
                                                    now_tm_local->tm_hour,
                                                    now_tm_local->tm_min,
                                                    now_tm_local->tm_sec);
    // struct tm => time_t
    time_t another_time = mktime(now_tm_local);
    printf("time(): %ld\n", another_time);
    return 0;
}
