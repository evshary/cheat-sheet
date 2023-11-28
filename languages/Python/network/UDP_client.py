import socket

my_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
msg = b"This is client message."
my_sock.sendto(msg, ('127.0.0.1', 4321))
print(my_sock.recv(128).decode('utf-8'))
my_sock.close()