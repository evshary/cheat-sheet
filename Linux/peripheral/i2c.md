# I2C

# Installation

```bash
sudo apt install i2c-tools
```

# Usage

* Get I2C bus: `sudo i2cdetect -l`
* Scan I2C bus: `sudo i2cdetect -r -y <i2c bus number>`
  - For example if we want to scan 0: `sudo i2cdetect -r -y 0`
  - You'll find some addresses shown if devices are connected.
* Dump the data of the address: `sudo i2cdump -f -y <i2c bus number> <device address>`
  - For example: `sudo i2cdump -f -y 0 0x50`
* Get the value of the register in the device: `sudo i2cset -f -y <i2c bus number> <device address> <register num>`
  - For example: `sudo i2cget -f -y 0 0x50 0x00`
* Set the value to the register in the device: `sudo i2cset -f -y <i2c bus number> <device address> <register num> <value>`
  - For example: `sudo i2cset -f -y 0 0x50 0x00 0x01`
