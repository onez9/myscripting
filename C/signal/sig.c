#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void listener(int sig) {
	printf("\nlistener: access violation\n");
	getchar();
}

 
void main() {
	//signal(SIGINT, SIG_IGN);
	//signal(SIGINT, SIG_DFL);
	do {
		printf("*");
	} while (1);
	

}
/*
void main() {
	char a = 10;
	char* p = &a;
	signal(SIGSEGV, listener);

	do {
		printf("%d ", *(p++));
	} while (1);
}
void main() {
	psignal(SIGQUIT, "helloworld");
	FILE* fo = NULL;
	fo = fopen("input.txt", "w");
	fprintf(fo, "Иди нахуй!");
	fclose(fo);
}
int value = -10;

void just_print(int sig) {
	//fprintf(stdout, "listener\n");
	printf("Делить на ноль нельзя!\n");
	extern int value;
	value += 1;//exit(0);
}

void main() {
	//sleep(10);

	signal(SIGFPE, just_print);
	//while(1) {
	//	printf("ctrl+c\n");
	//	getchar();
	//}
	//raise(SIGFPE);
	int num = 11;
	int p;
	printf("Введите число: ");
	scanf("%d", &p);
	extern int value;
	while (value <= 20) {
		printf("Enter value: ");
		printf("%d", 1/value);
		value++;
	}
	//int a = num/p;




	// set up a handler for the SIGINT signal
	//signal(SIGKILL, just_print);
	
	//signal(SIGINT, 0); // Выполнение процесса будет прервано
	// если вместо нуля поставить единицу данный сигнал будет проигнорирован
	// такое возможно но не для всех

	//http://www.opennet.ru/docs/RUS/lnx_process/process2.html

	//printf("begin\n");
	
	// send a signal
	//raise(SIGINT);
	//int snum;
	//scanf("%d", &snum);
	//kill(snum, SIGABRT);
	
	//fork(); // создаётся точно такой же процесс
	//execl("ls", "ls", 0);
	//printf("end\n");
	//getchar();
	//printf("%d\n", SIGINT);
	//printf("%d\n", SIGKILL);
	//fork();
}
*/
