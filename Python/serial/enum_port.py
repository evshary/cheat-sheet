import serial.tools.list_ports

coms=serial.tools.list_ports.comports()
for com in coms:
    print(com)