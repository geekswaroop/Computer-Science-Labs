import socket

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(("localhost",1233))

while True:
    data,addr = s.recvfrom(4096)
    print(str(data))
    msg = (bytes("Hello! This is the UDP connection server","utf-8"))
    s.sendto(msg,addr)