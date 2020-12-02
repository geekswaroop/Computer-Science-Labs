import socket
s=socket.socket()
s.bind(("127.0.0.1",1220))
s.listen(5)

while True:
	print("Server waiting for the connection")
	c,addr = s.accept()
	print("Server connected with ",addr)

	while True:

	    ex=c.recv(4092).decode()
	    ex=eval(ex)
	    ex.sort()
	    ex=str(ex)
	    c.send(bytes(ex,"utf-8"))

	c.close()
s.close()         


  
  


    
