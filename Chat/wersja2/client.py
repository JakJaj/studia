import socket

def sendPacket():
    proto = socket.getprotobyname('tcp')
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM,proto=proto)
    try:
        s.connect(("localhost",2222))
        s.send("Hello world".encode('utf-8'))

        resp = s.recv(1024)
        print(resp)
    except socket.error:
        pass
    finally:
        s.close()

if __name__ == "__main__":
    sendPacket()