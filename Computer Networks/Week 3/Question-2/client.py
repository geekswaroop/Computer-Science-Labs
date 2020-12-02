import socket
c=socket.socket()
c.connect(("127.0.0.1",1220))
try:
     while True:
          k=input("Input :")
          l=k.split(" ")
          l=str(l)
          l.encode()
          c.send(bytes(l,"utf-8"))
          print(end="    ")
          k=c.recv(4092)
          k=k.decode()
          k=eval(k)
          s=" ".join(k)
          print("\nOutput :\n",s)

except KeyboardInterrupt:
    print("Server Exited")

c.close()    



 
