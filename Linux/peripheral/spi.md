# SPI

In Linux, we need to use spidev-test to test SPI function

Refer to https://github.com/rm-hull/spidev-test

# Usage

* Get the code

```bash
git clone https://github.com/rm-hull/spidev-test
cd spidev-test
```

* Modify the SPI device name in code and then compile

```bash
gcc spidev_test.c -o spidev_test
```

* Run

```bash
printf '\x00\x01\x02\x03' > input.bin
xxd input.bin
./spidev_test -v -i input.bin
```
