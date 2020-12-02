import socket
import threading

PORT = 5050
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)  #Constant server address and the port it's running on
HEADER = 64 #Byte length of the initial message
FORMAT = 'utf-8'

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

def handle_client(conn, addr):
    print("Client Connected")
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            print(f"[{addr}]: {msg}")
            conn.send("Greeting client, this is server!".encode(FORMAT))

def start():
    server.listen()
    while True:
        conn, addr = server.accept()
        handle_client(conn, addr)

start()