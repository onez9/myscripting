import socket
import os
import pathlib
import threading


def listen_client(conn):
    while True:
        message = conn.recv(1024)
        message = message.decode('utf8')
        print(message)


if __name__ == '__main__':
    server = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    print(socket.gethostname())
    server.bind(('::1', 6666))
    server.listen()
    sock_conn_client, addr = server.accept()


    threading.Thread(target=listen_client, args=(sock_conn_client,)).start()




