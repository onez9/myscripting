#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// обработчик
void listener(int sig) {
	fprintf(stdout, "listener\n");
}

void main() {
	int status;
	// устанавливаем обработчик для сигнала SIGINT
	status = signal(SIGINT, listener);
	if (SIG_ERR == status) {
		fprintf(stdout, "error signal");
		exit(1);
	}
	printf("begin\n");
	printf("%d\n", SIG_ERR);
	// посылаем сигнал
	status = raise(SIGINT);
	if (0 != status) {
		fprintf(stdout, "error raise\n");
		exit(1);
	}
	fprintf(stdout, "end\n");
}
