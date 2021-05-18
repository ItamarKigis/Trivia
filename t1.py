import socket, json, sys

MAX_LEN = 1024
SOCKET = 8989
IP = '127.0.0.1'
LOGIN_CODE, SIGN_UP = 200, 210
LOGIN, SIGNUP = "login", "sign up"


def login(sock):
    user_info = {'username': "user1", 'password': "1234"}
    json_string = json.dumps(user_info)
    json_string = json_string.encode('ASCII')

    size_of_json = len(json_string).to_bytes(4,'big')

    msg = LOGIN_CODE.to_bytes(1,'big') + size_of_json + json_string
    sock.sendall(msg)
    printResponse(sock)

def sign_up(sock):
    user_info = {'username': "user2", 'password': "12345", 'email': "user1@gmail.com"}
    json_string = json.dumps(user_info)
    json_string = json_string.encode('ASCII')

    size_of_json = len(json_string).to_bytes(4,'big')

    msg = SIGN_UP.to_bytes(1,'big') + size_of_json + json_string
    sock.sendall(msg)
    printResponse(sock)

def printResponse(sock):
    response = str(sock.recv(MAX_LEN))
    temp = response.split("{")[1]
    print(temp.split("}")[0])

def main():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((IP, SOCKET))
        choice = input("Do you want to sign up or login? 1-Sign up, 2-Login")
        if choice == "1":
              sign_up(sock)
        elif choice == "2":
            login(sock)
        sock.close()
    except:
        print("coundlnt connect server")



if __name__ == '__main__':
    main()
