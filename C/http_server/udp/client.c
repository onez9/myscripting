#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <malloc.h>

#define PORT 8080 
#define MAXLINE 1024 
  
// Driver code 
int main() { 
	int sockfd; 
	char buffer[MAXLINE]; 
	struct sockaddr_in servaddr; 

	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	  
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = inet_addr("192.168.1.198");
	//servaddr.sin_addr.s_addr = INADDR_ANY; 
	  
	int n, len; 
	


	char *hello = (char*)malloc(sizeof(char) * 100);
	//scanf("%s", hello);
	fgets(hello, 100, stdin);

	// Отправляем сообщение на сервер
	sendto(sockfd, (const char *)hello, strlen(hello),\
			MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
	

	printf("Message sent.\n"); 
		  
	// Получаем ответ с сервера
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL,\
			(struct sockaddr *) &servaddr, &len); 


	
	buffer[n] = '\0'; 
	printf("Server : %s\n", buffer); 
	
	// ну вы поняли
	close(sockfd); 
	return 0; 
} 
