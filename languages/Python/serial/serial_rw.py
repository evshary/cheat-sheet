import serial

# set serial setting
ser = serial.Serial()
ser.baudrate = 115200
ser.port = "COM1"
# open port
ser.open()
# write data
ser.write(b'hello')
# receive data
print(ser.readline())
# close port
ser.close()