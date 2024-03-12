#include <stdio.h>

void main() {
	FILE* f;
	char str[128];
	char* str1;
	f = fopen("input.txt", "r");
	/*
	for (int i=0;i<10;i++) {
		//str1 = fgets(str, 128, f);
		
		printf("%s", str);
	}
	*/
	// Правильное чтение из файла
	char sh;
	while ((sh = fgetc(f)) != EOF) {
		printf("%c", sh);
	}
	printf("\n");
	fclose(f);
	// Неправильное чтение из файла

	sh = ' ';
	f = fopen("input.txt", "r");
	while (sh != EOF) {
		sh = fgetc(f);
		printf("%c", sh);
	}
	//printf("%s", str1);
	fclose(f);
}
