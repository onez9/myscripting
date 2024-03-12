#include <stdio.h>
#include <stdbool.h>
#include "Other.h"
#include <time.h>
#include <stdlib.h>
#include <malloc.h>


void main() {
	int a,b,c;
	printf("Enter a,b:\n");
	scanf("%d,%d", &a, &b);
	c = euc2(a,b);
	printf("%d\n", c);
	

	srand(time(NULL));
	int n;
	printf("Enter n: \n");
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i=0;i<n;i++) {
		arr[i] = rand() % 10;
	}

	for (int i = 0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");:



}
