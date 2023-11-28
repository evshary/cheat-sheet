import socket

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Connect to server
mysock.connect(('127.0.0.1',8080))
try:
    msg = b"This is client message."
    mysock.sendall(msg)
except OSError as e:
    print("Socket Error:", e)
finally:
    mysock.close()