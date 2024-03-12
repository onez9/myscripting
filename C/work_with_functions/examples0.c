#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

void show(int* arr, unsigned size) {
	srand(time(NULL));
	unsigned i;
	for (i=0;i<size;i++) {
		*(arr + i) = rand() % 10;
		printf("%d - %d \n",i, *(arr + i));
	}
}

int main() {
	void (*fun)(int*, unsigned);
	fun = show;
	unsigned siz = 18;
	int* a = (int*)malloc(sizeof(int) * siz);
	fun(a, siz);
}
