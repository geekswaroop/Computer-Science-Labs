import socket
import threading

username = input("Choose your username: ")


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = "localhost"
client.connect((host, 5000))


def receive():
    while True:
        try:
            
            message = client.recv(1024).decode('ascii')
            if message == 'USER':
                client.send(username.encode('ascii'))
            else:
                print(message)
        except:
            
            print("An error occured!")
            client.close()
            break


def write():
    while True:
        message = '{}: {}'.format(username, input(''))
        client.send(message.encode('ascii'))
        



receive_thread = threading.Thread(target=receive)
receive_thread.start()

write_thread = threading.Thread(target=write)
write_thread.start()
