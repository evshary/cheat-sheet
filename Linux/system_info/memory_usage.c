#include <stdio.h>

// Reference: https://stackoverflow.com/questions/41224738/how-to-calculate-system-memory-usage-from-proc-meminfo-like-htop
int get_memory_usage(void)
{
    char column[20], dummy[20];
    unsigned int total_mem, free_mem, buffer_mem, cached_mem, dummy_num;
    FILE *fp;

    fp = fopen("/proc/meminfo", "r"); 
    fscanf(fp, "%s %u %s", column, &total_mem, dummy);
    fscanf(fp, "%s %u %s", column, &free_mem, dummy);
    fscanf(fp, "%s %u %s", column, &dummy_num, dummy);
    fscanf(fp, "%s %u %s", column, &buffer_mem, dummy);
    fscanf(fp, "%s %u %s", column, &cached_mem, dummy);
    fclose(fp);

    printf("Total memory: %d\n", total_mem);
    printf("Available memory: %d\n", free_mem + buffer_mem + cached_mem);
    printf("Used memory: %d\n", total_mem - free_mem - buffer_mem - cached_mem);

    return (total_mem - free_mem - buffer_mem - cached_mem) * 100 / total_mem;
}

int main(void)
{
    printf("Memory usage: %d\n", get_memory_usage());
    return 0;
}
