#include <stdio.h>
#include <unistd.h>

// Refer to https://stackoverflow.com/questions/3017162/how-to-get-total-cpu-usage-in-linux-using-c
int get_cpu_usage(void)
{
    char column[10];
    unsigned int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    unsigned int total_jiffies[2], work_jiffies[2];
    FILE *fp;

    for (int i = 0; i < 2; i++) {
        fp = fopen("/proc/stat", "r"); 
        fscanf(fp, "%s %u %u %u %u %u %u %u %u %u %u", column, &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        total_jiffies[i] = user + nice + system + idle + iowait + irq + softirq;
        work_jiffies[i] = user + nice + system;
        fclose(fp);
        if (i == 0) usleep(500000); // sleep 500ms
    }

    return (work_jiffies[1] - work_jiffies[0]) * 100 / (total_jiffies[1] - total_jiffies[0]);
}

int main()
{
    printf("CPU usage: %d\n", get_cpu_usage());
    return 0;
}
