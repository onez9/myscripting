#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 


#define PORT 8080 // порт
#define MAXLINE 1024 // размер буфера
  
// Driver code 
int main() { 
	int sockfd;
	//"Данные принимаемые от клиентов"
	char buffer[MAXLINE]; 
	struct sockaddr_in servaddr, cliaddr; 
	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 

	// Filling server information 
	servaddr.sin_family    = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = inet_addr("192.168.1.198");
	//servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 

	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 

	int len, n; 
	char *hello = "Hello from server"; 

	len = sizeof(cliaddr);  //len is value/resuslt 
	while(1){
		// 
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL,\
				(struct sockaddr *) &cliaddr, &len);
		buffer[n] = '\0';
		printf("Client : %s\n", buffer);

		// Параметр flags является битовой маской и может содержать такие флаги: 
		// send, sendto, sendmsg - отправляет сообщения в сокет
		// MSG_CONFIRM - только для UNIX
		sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM,\
				(const struct sockaddr *) &cliaddr, len);
		printf("Hello message sent.\n");
	}
	return 0; 
} 

