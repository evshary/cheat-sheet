import socket

s_fd = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s_fd.bind(('127.0.0.1', 4321)) # Bind the port
# Send data
data, addr = s_fd.recvfrom(128)
print('Client from %s:%s' % addr)
print("Data=%s" % data)
s_fd.sendto(b"This is server message.", addr)