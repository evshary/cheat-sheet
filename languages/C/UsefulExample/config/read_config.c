#include <stdio.h>

#define LINE_LEN 1024
#define CONFIG_NAME "myconfig.conf"

int main(int argc, char *argv[])
{
    int ret = 0;
    char line[LINE_LEN];
    char key[128];
    char value[256];
    int line_num = 0;

    FILE *fp = fopen(CONFIG_NAME, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to find %s\n", CONFIG_NAME);
        ret = -1;
        goto exit;
    }
    printf("Start to read config.\n");

    while (fgets(line, LINE_LEN, fp) != NULL) {
        line_num++;
        if (line[0] == '#' || line[0] == '\n') continue;
        if (sscanf(line, "%[^:]:%s", key, value) != 2) {
            fprintf(stderr, "Syntax error: line %d\n", line_num);
            continue;
        }
        printf("Line %d: key=%s, value=%s\n", line_num, key, value);
    }

    fclose(fp);
exit:
    return ret;
}
