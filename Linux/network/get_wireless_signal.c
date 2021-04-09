#include <stdio.h>

int main(void)
{
    char buffer[512];
    FILE *fp;
    char interface[24];
    int rssi;

    fp = fopen("/proc/net/wireless", "r");

    // skip the first 2 lines
    for (int i = 0; i < 2; i++) {
        fgets(buffer, sizeof(buffer), fp);
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%[^:]: %*s %*d. %d. %*d %*d %*d %*d %*d %*d %*d\n",
               interface, &rssi);
        printf("interface: %s, rssi: %d\n", interface, rssi);
    }
    fclose(fp);

    return 0;
}
