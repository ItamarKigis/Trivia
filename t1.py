import socket, json, sys

MAX_LEN = 1024
SOCKET = 8989
IP = '127.0.0.1'
LOGIN_CODE, SIGN_UP = 200, 210
LOGIN, SIGNUP = "login", "sign up"


def login(sock):
    user_info = {'username': "user1", 'password': "1234"}
    json_info = bytes(to_json(user_info).encode())
    size_of_json = sys.getsizeof(json_info)
    msg = (bytes((f'{LOGIN_CODE:08b}').encode())) + bytes(format(size_of_json, '032b').encode()) + json_info
    sock.sendall(msg)


def sign_up(sock):
    user_info = {'username': "user1", 'password': "1234", 'email': "user1@gmail.com"}
    json_info = bytes(to_json(user_info).encode())
    size_of_json = sys.getsizeof(json_info)
    msg = (bytes((f'{SIGN_UP:08b}').encode())) + bytes(format(size_of_json, '032b').encode()) + json_info
    sock.sendall(msg)

def to_json(user_info):
    j_dump = json.dumps(user_info)
    return ''.join(format(ord(letter), 'b') for letter in j_dump)

def main():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((IP, SOCKET))
        choice = input("Do you want to sign up or login? 1-Sign up, 2-Login")
        if choice == "1":
            sign_up(sock)
        elif choice == "2":
            login(sock)
    except:
        print("coundlnt connect server")
        sock.close()


    sock.close()


if __name__ == '__main__':
    main()
