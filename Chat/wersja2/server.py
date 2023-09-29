import socket

def server():
    proto = socket.getprotobyname('tcp')
    serv = socket.socket(socket.AF_INET,socket.SOCK_STREAM,proto=proto)
    serv.bind(('localhost',2222))
    serv.listen(1)
    return serv

serv = server()

while 1:
    conn,addr = serv.accept()
    while 1:
        message = conn.recv(64)
        if message:
            conn.send(f"Hi, Im server, I receve {message.decode('utf-8')}".encode('utf-8'))
        else:
            break
    conn.close()