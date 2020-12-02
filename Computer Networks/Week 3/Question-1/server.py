#1)Create a server and client communication wherein the client should communicate with the server. The server waits for user messages from client. If server receives message “Bye” from client, it replies “Bye”. For any other string, server replies the same message but after making it into capital letters. The client is closed, when it gets the message “Bye” from server.
#4)Create a server and client communication wherein the client should ask the services of a math server. It should be implemented using concurrent servers where multiple clients can request the service from server. The user enters a simple arithmetic expression string (e.g., "1 + 2", "5 - 6", "3 * 4").  The expression is evaluated by the server and then the result is send back to the client from the server side. The client should display the server's reply to the user, and prompt the user for the next input, until the user terminates the client program with Ctrl+C. 

import socket
import threading

PORT = 5053
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)  #Constant server address and the port it's running on
HEADER = 64 #Byte length of the initial message
FORMAT = 'utf-8'
DISCONNECT_MSG = "Bye"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #create server
server.bind(ADDR)  #Bind the port and the server socket together

def handle_client(conn, addr): #handles client message. Takes in client connection socket and it's address
    print(f"[NEW CONNECTION]: {addr} Connected")
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MSG:
                connected = False
            print(f"[{addr}]: {msg}")
            if msg == DISCONNECT_MSG:
                conn.send(msg.encode(FORMAT))
            else:
                ans = msg.upper()
                conn.send(ans.encode(FORMAT))
    conn.close()

            


def start(): #Allows server to listen to connections. Once received, calls handle_client
    server.listen()  #Start listening for new connections
    print(f"[LISTENING] Server is listening on {SERVER}")
    while True:
        conn, addr = server.accept()  #Client connection is intercepted. It will keep waiting till a new connection is coming. conn = socket object, addr = IP and Port of client
        thread = threading.Thread(target = handle_client, args = (conn, addr)) #So, a client is connected, a thread is created and it's relavent function to runs is passed here
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.activeCount() -1}") #We subtract one because there's one starting thread



print("[STARTING] Server is starting")
start()


