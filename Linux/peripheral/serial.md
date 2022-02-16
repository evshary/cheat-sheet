# Architecture

* serial port/COM port: The hardware of serial communication, mostly used DB9.
* UART/USART: Define the communication protocol layer(i.e. baudrate, 8N1...). TTL/RS232/RS485 all belong to UART.
  - The difference between USART and UART is that USART includes clock pin, but it can also run as UART.
* TTL/RS232/RS485: Define the signal and voltage of each pin. Note that TTL is not compatible to RS232.

![image](https://user-images.githubusercontent.com/456210/150623539-a19687f7-e199-47a8-bc93-44f57c065f6b.png)

# Usage

* The debug port we use is TTL mostly, and needs to transform from RS232 to TTL.

```
COM port from host PC (often RS232)  ---> MAX232 (Chip from MAXIM, RS232 to TTL) ---> debug port (UART in embeded system)
```

* If you only have USB in your computer

```
USB from host PC ---> CH340/PL2303/CP2102 (USB to TTL) ---> debug port (UART in embeded system)
```

# Reference
* [串口，COM口，TTL，RS232，RS485，UART的區別詳解](https://kknews.cc/zh-tw/news/2yeqr6y.html)
* [UART、RS232、TTL关系浅析](https://zhuanlan.zhihu.com/p/25893717)
