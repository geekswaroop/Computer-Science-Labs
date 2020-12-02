import socket

HEADER = 64
PORT = 5051
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)  #Constant server address and the port it's running on
HEADER = 64 #Byte length of the initial message
FORMAT = 'utf-8'
DISCONNECT_MSG = "!DISCONNECT"


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

def send(msg):
    message = msg.encode(FORMAT)   #Enocde to bytes
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' ' * (HEADER - len(send_length)) #Make send_length = 64
    client.send(send_length)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))

send(" ")
