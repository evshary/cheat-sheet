#include <unistd.h>
#include <stdio.h>
#include <termio.h>

int getKeyboard() {
    int ret;
    struct termios origin_settings, new_settings;
    tcgetattr(STDIN_FILENO, &origin_settings);
    new_settings = origin_settings;
    new_settings.c_lflag &= ~ICANON; // Non-canonical mode
    new_settings.c_cc[VTIME] = 0;    // No timeout
    new_settings.c_cc[VMIN] = 1;     // Return while reading 1 char
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    ret = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &origin_settings);
    return ret;
}

int main() {
    while (1) {
        printf(": %d\r\n", getKeyboard());
    }
    return 0;
}
