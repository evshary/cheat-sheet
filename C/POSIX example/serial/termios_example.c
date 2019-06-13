#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define COM1 "/dev/ttyS0"
#define BAUD B115200
#define MAXBUF 128

int main(){
    int fd_S0;
    struct termios options;
    int ret;
    char buffer[MAXBUF] = {0};

    fd_S0 = open(COM1, O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd_S0 == -1){
        printf("[ERROR] unable to open!\n");
        return -1;
    }

    // get old options
    tcgetattr(fd_S0, &options);
    // set baud rate
    cfsetispeed(&options, BAUD);
    cfsetospeed(&options, BAUD);
    // set 8N1
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    // enable flow control
    options.c_cflag |= CRTSCTS;
    // enable the receiver and set local mode
    options.c_cflag |= (CLOCAL | CREAD);
    // use non canonical mode
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    // set non canonical timeout
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;
    // set options
    tcsetattr(fd_S0, TCSANOW, &options);

    strcpy(buffer, "testabc");
    ret = write(fd_S0, buffer, strlen(buffer));
    printf("Write data: %s\n", buffer);
    ret = read(fd_S0, buffer, sizeof(buffer));
    printf("Read data len %d: %s\n", ret, buffer);

    close(fd_S0);
    return 0;    
}
