#include <stdio.h>
#include <malloc.h>
#include <string.h>

void main(){
	char* str = (char*)malloc(sizeof(char) * 10);
	scanf("%s", str);
	printf("%ld", strlen(str));
	free(str);
}
