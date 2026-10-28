import socket 

HOST = "10.47.126.196"
PORT = 1234

s = socket.socket()
s.connect((HOST, PORT))

values = []

while True:
    data = s.recv(1024).decode().strip()
    value = data
    values.append(value)
    print(value)
                