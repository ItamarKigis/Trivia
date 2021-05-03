import socket, json

MAX_LEN = 1024
SOCKET = 8989
IP = '127.0.0.1'
LOGIN_CODE, SIGN_UP = 200, 210
LOGIN, SIGNUP = "login", "sign up"


def login(sock):
    user_info = {'username': "user1", 'password': "1234"}
    msg = json.dumps(LOGIN_CODE) + json.dumps(len(user_info)) + json.dumps(user_info)
    sock.sendall(msg.encode())


def sign_up(sock):
    user_info = {'username': "user1", 'password': "1234", 'mail': "user1@gmail.com"}
    msg = json.dumps(LOGIN_CODE) + json.dumps(len(user_info)) + json.dumps(user_info)
    sock.sendall(msg.encode())


def main(name, msgType):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((IP, SOCKET))
    except:
        print("coundlnt connect server")
        sock.close()

    if lower(msgType) == LOGIN:
        login(sock)
    elif lower(msgType) == SIGN_UP:
        sign_up(sock)

    sock.close()


if __name__ == '__name__':
    main('PyCharm')
