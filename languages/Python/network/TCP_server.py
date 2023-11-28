import socket

# create socket
s_fd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# set socket option
s_fd.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
# listening to local port 8080
s_fd.bind(('127.0.0.1', 8080))
# max connection is 10
s_fd.listen(10)

# accept connection from client
c_fd, addr = s_fd.accept()
# receive data
recv_size = 128
data = c_fd.recv(recv_size)
print("Client from %s:%s" % addr)
print("Data=%s" % data)

s_fd.close()