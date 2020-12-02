import socket

c = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
c.connect(("127.0.0.1",1231))
payload = "Hello Server"

try:
    while True:
        c.send(payload.encode('utf-8'))
        data = c.recv(1024)
        print(str(data))
        more = input("Want to send messages to the server ?(y/n)")
        if more.lower()=='y':
            payload = input("Enter the message : ")
        else:
            break
except KeyboardInterrupt:
    print("Server Exited")
c.close()