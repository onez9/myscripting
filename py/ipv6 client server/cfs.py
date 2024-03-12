import socket
import ipaddress


client = socket.socket(socket.AF_INET6, socket.SOCK_STREAM, 0)
# host = "::1"
# host = "127.0.0.1"
# host = "192.168.1.16"
# host = socket.gethostname()
# host = socket.getaddrinfo("::1", 6666, socket.AF_INET6)
# host = ipaddress.IPv6Address("fe80::1beb:81b2:ce8a:28a7")
host = "fe80::1beb:81b2:ce8a:28a7" # другой комп :)
# host = "::1" # если на локалке
# host = "::" # current address for global world what? what? what?
# host = (str(address))
# host = "localhost"
# address = address.upper()
port = 6666
# res = socket.getaddrinfo(host, port, socket.AF_UNSPEC, socket.SOCK_DGRAM, 0, socket.AI_PASSIVE)
# family, socktype, proto, canonname, sockaddr = res[1]
# print(sockaddr)
addr = (host, port, 0, 0)
client.connect(addr)

with open('bubu.jpg', 'rb') as fi:
    data = fi.read(2048)
    while data:
        client.send(data)
        data = fi.read(2048)






