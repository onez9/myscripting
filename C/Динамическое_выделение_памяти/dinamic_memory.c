#include <stdio.h>
#include <malloc.h>

void main(){
	int *a;
	int i, n;
	printf("Enter size of array\n");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (i=0;i<n;i++){
		printf("a[%d] = ", i);
		scanf("%d", a+i);
	}
	for (int i=0;i<n;i++){
		printf("a[%d] = %d\n", i, *(a+i));
	}
	free(a);
	int e = 2;
	printf("%d", 2+2*2);
}
