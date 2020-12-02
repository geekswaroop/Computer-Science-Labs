import socket

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("127.0.0.1",1231))
s.listen(4)

while True:
    print("Server waiting for connection...")
    c,addr = s.accept()
    print("The Client Connected:  ",addr)

    while True:
        data = c.recv(1024)
        if not data or data.decode('utf-8')=='END':
            break
        print("Message received from the client : %s" %data.decode('utf-8'))
        try:
            c.send(bytes(input("Enter any message for the client :"),'utf-8'))
        except KeyboardInterrupt:
            print("User Exited")
    c.close()
s.close()