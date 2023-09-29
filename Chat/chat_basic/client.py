import socket
proto = socket.getprotobyname('tcp')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM,proto)
client.connect(("localhost", 2222))

done = False

while not done:
    client.send(input("Wiadomosc: ").encode('utf-8'))
    msg = client.recv(1024).decode('utf-8')
    if msg.lower() == 'koniec':
        done = True
    else:
        print(msg)