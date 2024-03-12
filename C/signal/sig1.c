#include <stdio.h>
#include <unistd.h> // fork(), sleep()
#include <sys/wait.h>

void main() {
	int a = fork();
	//if (a == 0) wait(0);
	//else execl("ls", "ls", 0);
	//7:11

	printf("%d\n", a);
	sleep(10);

}
