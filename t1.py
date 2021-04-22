import socket
SOCKET = 8989
IP = '127.0.0.1'


def main(name):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((IP, SOCKET))
        data = sock.recv(1024)
        print(data.decode())
        if data.decode() != "Hello":
            sock.send("Hello".encode())
    except:
        print("Could not connect to the server!")
if __name__ == '__main__':
    main('PyCharm')
