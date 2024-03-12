#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


void error(const char *msg)
{
    perror(msg);
    exit(0);
}

void main(int argc, char *argv[]) {
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if (argc < 3) {
		fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}

	// Задаем номер порта
	portno = atoi(argv[2]);

	// Создаем сокет
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");

	// Конвертирует имя хоста в IP адрес
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		fprintf(stderr,"ERROR, no such host\n");
		exit(0);
	}

	// Указываем тип сокета Интернет
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;

	// Указаваем адрес IP сокета
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

	// Указываем порт сокета
	serv_addr.sin_port = htons(portno);

	// Устанавливаем соединение
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	// Вводим сообщение из консоли
	printf("Please enter the message: ");
	bzero(buffer, 256);
	fgets(buffer, 255, stdin);

	// Отправляем данные
	n = write(sockfd, buffer, strlen(buffer));
	if (n < 0)
		 error("ERROR writing to socket");

	// Сбрасываем буфер
	bzero(buffer, 256);

	// Читаем ответ
	n = read(sockfd, buffer, 255);
	if (n < 0)
		 error("ERROR reading from socket");
	printf("%s\n", buffer);

	close(sockfd);
}
