import socket

proto = socket.getprotobyname('tcp')
server = socket.socket(socket.AF_INET,socket.SOCK_STREAM,proto)
server.bind(("localhost", 2222))
server.listen(1) 
client, addr = server.accept()

done = False
while not done:
    msg = client.recv(1024).decode('utf-8')

    if msg.lower() == 'koniec':
        done = True
    else:
        print(msg)
    client.send(input("Wiadomosc: ").encode('utf-8'))