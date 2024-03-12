#include <stdio.h>
#include <malloc.h>

void main() {
	int n = 1000000000;
	
	int *arr = (int*)malloc(sizeof(int) * n);
	for (unsigned i = 0; i < n; i++) {
		arr[i] = i;
		printf("%d\n", arr[i]);
	}

	

	printf("%d\n", n);
}
