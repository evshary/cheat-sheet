# Basic Operation
* open/close
```c
/*
  - O_RDWR: Able to read & write
  - O_NOCTTY: Prevent process stopping by keyboard
  - O_NDELAY: Ignore DCD
  - O_NONBLOCK: Non block mode
 */
int fd = open(“/dev/ttyS0”, O_RDWR | O_NOCTTY | O_NDELAY);
// open with non block mode
int fd = open(“/dev/ttyS0”, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
//set DTR low and stop modem
close(fd);
```
* read/write
```c
int n = write(fd, “ATZ\r”, 4);
int n = read(fd, buff, MAXBUF);
```
* Change fd setting
```c
#include <unistd.h>
#include <fcntl.h>
// EX: from Block mode to Nonblock mode
int old_settings = fcntl(fd, F_GETFL, 0);
fcntl(fd, F_SETFL, old_settings | O_NONBLOCK);
```

# structure
* c_iflag: How to handle input char, like parity
* c_oflag: How to display output, like newline<=>CRLF
* c_cflag: Control serial settings
* c_lflag: Communications between user and driver
* c_cc: Special characters

```c
#include <termios.h>

struct termios {
	tcflag_t c_iflag; /* input flag */
	tcflag_t c_oflag; /* output flag */
	tcflag_t c_cflag; /* control flag */
	tcflag_t c_lflag; /* local flag */
	cc_t c_cc[NCCS];  /* control characters */
	speed_t c_ispeed;
	speed_t c_ospeed;
};
```

# Settings
## function
* Prototype
```c
#include <termios.h> 
int tcgetattr(int filedes, struct termios *termptr); 
/*
opt:
  - TCSANOW: change now
  - TCSADRAIN: change after sending output
  - TCSAFLUSH: change after sending output and discard input
*/
int tcsetattr(int filedes, int opt, const struct termios * termptr);
```
* Example
```c
struct termios options; 
tcgetattr(fd, &options); 
// setting baudrate to 115200
cfsetispeed(&options, B115200);
cfsetospeed(&options, B115200);
// Data bits: 8
options.c_cflag &= ~CSIZE; 
options.c_cflag |= CS8;
options.c_cflag |= PARENB
// Parity: None
options.c_cflag &= ~PARENB
// Stop bits: 1
options.c_cflag &= ~CSTOPB
// Always enable CREAD and CLOCAL
// - CREAD: enable receiver
// - CLOCAL: ignore modem response
options.c_cflag |= (CLOCAL | CREAD); 
tcsetattr(fd, TCSANOW, &options);
```

## baudrate
* Baudrate MACRO
  - B50, ..., B4800, B9600, B19200, B38400, B57600, B115200, B230400
```c
// input baudrate
cfsetispeed(&options, B19200);
// output baudrate
cfsetospeed(&options, B19200);
```

## 8N1 settings
* Data bits
```c
// clear with CSIZE
options.c_cflag &= ~CSIZE; 
// Set CS5-CS8
options.c_cflag |= CS7;
```
* Parity
```c
// Enable parity
options.c_cflag |= PARENB
// PARODD: odd parity
// ~PARODD: even parity
options.c_cflag &= ~PARODD 
```
* Stop bits
```c
// CSTOPB: using 2 stop bits
// ~CSTOPB: others
options.c_cflag &= ~CSTOPB
```

## Flow control
* HW (RTS/CTS)
```c
// enable
options.c_cflag |= CNEW_RTSCTS;
// disable
options.c_cflag &= ~CNEW_RTSCTS;
```
* SW (XON/XOFF)
```c
// enable
options.c_iflag |= (IXON | IXOFF | IXANY);
// disable
options.c_iflag &= ~(IXON | IXOFF | IXANY);
```

## Canonical/Non-canonical mode
* Canonical mode
  - Terminal input is processed as lines.
  - Special char is processed.
  - EX: shell
* Non-canonical mode
  - Input chars are not assembled into lines.
  - Specail char is not processed.
  - EX: vim
* Settings
```c
// Canonical mode (cooked mode)
// - ECHO: input will echo to output
// - ECHOE: backspace will clean the last char
options.c_lflag |= (ICANON | ECHO | ECHOE);
// Non-canonical mode (raw mode)
// - ISIG: special char will cause signal
options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
```
* Special char c_cc(VMIN, VTIME) is important to Non-canonical mode

| - | VMIN > 0 | VMIN == 0 |
| --- | --- | --- |
| VTIME > 0 | return while reading MIN char or VTIME is timeout | return while reading first char or VTIME is timeout |
| VTIME == 0 | return while reading MIN char | return immediately |

## Ouput process
```c
// Enable
options.c_oflag |= OPOST;
// newline to CRLF
options.c_oflag |= ONLCR;
// Disable
options.c_oflag &= ~OPOST;
```

# Useful function
* tcdrain: Waiting the output data is all cleared
```c
int tcdrain(int filedes);
```
* tcflow: Enable/Disable the data transmit(send/recv)
```c
/* action
  - TCOON: Enable Output
  - TCOOFF: Disable Output
  - TCION: Enable Input
  - TCIOFF: Disable Input
 */
int tcflow(int filedes, int action); 
```
* tcflush: Clear the input/output queue
```c
/* queue
  - TCIFLUSH: Clear input queue
  - TCOFLUSH: Clear output queue
  - TCIOFLUSH: Clear input/output queue
 */
int tcflush(int filedes, int queue); 
```
* tcsendbreak
```c
// duration depends on implementation
int tcsendbreak(int filedes, int duration);
```

# Example
Please refer to [termio_example.c](termio_example.c).
