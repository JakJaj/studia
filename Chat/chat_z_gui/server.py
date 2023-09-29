import socket
import threading

proto = socket.getprotobyname('tcp')
HOST = 'localhost'
PORT = 2222

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM,proto=proto)
server.bind((HOST,PORT))
server.listen()

clients = []
nicknames = []

def broadcast(message):
    '''Wysylanie wiadomosci do wszystkich klientow'''
    for client in clients:
        client.send(message)

def handle(client):
    '''Zarzadzanie klientami wiadomosci od klientow'''
    while True:
        try:
            message = client.recv(1024)
            print(f"<{nicknames[clients.index(client)].decode('utf-8')}>  {message}")
            broadcast(message)
        except:
            
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            nicknames.remove(nickname)
            break

def recive():
    '''Odbieranie wiadomosci od klientow'''
    while True:
        client, address = server.accept()
        print(f"Polaczono z {str(address)}")

        client.send("NICKNAME".encode('utf-8'))
        nickname = client.recv(1024)

        nicknames.append(nickname)
        clients.append(client)

        print(f"Nowy uzytkownik: {nickname}\n")
        broadcast(f"{nickname} dolaczyl do chatu\n".encode('utf-8'))
        client.send("Polaczono z serverem\n".encode('utf-8'))

        thread = threading.Thread(target=handle, args=(client,))
        thread.start()

print("-----Serwer dziala-----")
recive()