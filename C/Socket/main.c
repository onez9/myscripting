#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

//#include <netdb.h>

void main(int argc, char *argv[]) {
	int sockfd;
	int aaaa;
	int bbbb;
	int opt = 1;
	char buffer[1024] = {0};
	struct sockaddr_in address;
	int addrlen = sizeof(address);

	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("192.168.1.108");
	address.sin_port = htons( PORT );
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bind(sockfd, (struct sockaddr*)&address, sizeof(address) < 0);
	listen(sockfd, 10);
	aaaa = accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
	bbbb = read(aaaa, buffer, 1024);
	char* hello = "hello from server!";
	send(aaaa, hello, strlen(hello), 0);
	
}
