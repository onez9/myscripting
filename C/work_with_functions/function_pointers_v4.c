#include <stdio.h>
#include <malloc.h>
void main() {
	/*int* arr[10];
	for (int i=0;i<10;i++) {
		arr[i] = (int*)malloc(sizeof(int));
		*arr[i] = i;
		printf("%d\n", *arr[i]);
	}
	printf("Enter value: ");
	*/
	int n;
	scanf("%d", &n);
	int **arr;
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i=0;i<n;i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			arr[i][j] = (i * j) % 10;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i=0;i<n;i++) {
		free(arr[i]);
	}
}
