import socket

server = socket.socket(socket.AF_INET6, socket.SOCK_STREAM, 0)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# host = "::1" # localhost
host = "::"  # тоже но работает, для виртуальной тачки, и не работает, как localhost
port = 6666
addr = (host, port, 0, 0)
server.bind(addr)
server.listen(10)

print("Ожидание новых подключений!")
client_socket, client_address = server.accept()

print("Ожидание приёма данных!")
data = client_socket.recv(2048)

with open('recvfile.jpg', 'wb') as fo:
    while data:
        fo.write(data)
        data = client_socket.recv(2048)





