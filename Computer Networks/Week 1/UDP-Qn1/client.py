import socket

c = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

ms = "Hello UDP Connection Server!, This is Client here"
c.sendto(ms.encode('utf-8'),("localhost",1235))
data,addr = c.recvfrom(4096)
print("Server message: ")
print(str(data))
c.close()