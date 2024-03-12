#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
	char *arr = (char*)malloc(sizeof(char)*100);
	memset(arr, 'x', 100);
	memset(arr, 'z', 10);
	for(int i=0;i<100;i++){
		printf("%d %c\n", i, arr[i]);
	}
	return 0;
}
