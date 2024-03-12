import socket
import logging
import threading


def sending(connserver):
    while True:
        msg = input()
        connserver.send(msg.encode('utf8'))


def listing(connserver):
    while True:
        message = connserver.recv(1024)
        message = message.encode('utf8')
        print(message)


if __name__=='__main__':
    ipaddr = '::1'
    client = socket.socket(socket.AF_INET6, socket.SOCK_STREAM, 0)
    client.connect((ipaddr, 6666))

    # ttt = True
    threading.Thread(target=sending, args=(client,)).start()
    threading.Thread(targed=listing, args=(client,)).start()



    # while ttt:
    #     # msg=input()
    #     try:
    #         # client.send(msg.encode('utf-8'))
    #         filename='simpletext.txt'
    #         client.send(filename.encode('utf8'))
    #         message = client.recv(1024)
    #         message = message.decode('utf8')
    #     except Exception as e:
    #         print(e)
    #     finally:
    #         # string = 'buGWGubgGYRWbuubu'
    #         ttt = False
    #         # print(string.upper())
    #         # print(string.lower())





