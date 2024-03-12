#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* args) {
	printf("hello world!\n");
	return 0;
}

void main() {
	pthread_t thread;
	int status;
	int status_addr;
	status = pthread_create(&thread, NULL, func, NULL);
	if (status != 0) {
		printf("невозможно создать поток\n");
		exit(-11);
	}
	printf("hello from main!\n");
	status = pthread_join(thread, (void**)&status_addr);
	if (status != 0) {
		printf("Невозможно объеденить потоки\n");
		exit(-12);
	}
	printf("joined with address %d\n", status_addr);

}
