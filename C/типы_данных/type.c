#include <stdio.h>

void main() {
	printf("int - %10d\n", sizeof(int));
	printf("float - %10d\n", sizeof(float));
	printf("double - %10d\n", sizeof(double));
	printf("short int- %10d\n", sizeof(short int));
	printf("signed short - %10d\n", sizeof(signed short));
	printf("signed short int - %10d\n", sizeof(signed short int));
	printf("unsigned int - %10d\n", sizeof(unsigned int));
	printf("long double - %10d\n", sizeof(long double));
	printf("double - %10d\n", sizeof(double));
	printf("------------------\n");

	int t = 47;
	int *ptr = &t;

	printf("%p\n", ptr);
	printf("%d\n", *ptr);
	scanf("%d", &t);
	int arr[t];
	
}
