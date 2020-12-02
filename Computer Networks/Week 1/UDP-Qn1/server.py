import socket

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("localhost",1235))

while True:
    data,addr = s.recvfrom(4096)
    print(str(data))
    msg = (bytes("Hi there! This is UDP connection server","utf-8"))
    s.sendto(msg,addr)