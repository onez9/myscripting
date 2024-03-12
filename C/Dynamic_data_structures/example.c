#include <stdio.h>
#include <malloc.h>

void main() {
	int* a;
	a = (int*)malloc(sizeof(int));
	*a = 7;
	printf("*a == %d\n", *a);
	free(a);
	printf("%#x\n", a);
	printf("*a == %d\n", *a);
	printf("%#x\n", a);
}
