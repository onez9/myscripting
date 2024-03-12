#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
void main(){
	int *arr;
	
	int n;
	printf("Enter num: ");
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));

	for (int i=0;i<n+20;i++){
		arr[i] = i;
	}
	printf("%d", sizeof(arr));
	
	for (int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
	arr = (int*)realloc(arr, n * 2 * sizeof(int));
	for (int i=n;i<30;i++){
		*(arr+i) = 11;
	}
	for (int i=0;i<30;i++){
		printf("%x - %d\n", &arr[i], arr[i]);
	}





}
