#include <stdio.h>
#define NAME "Zakhar Aramilev\n"

void main() {
	int n = 3;
	int array[3] = {1, 2, 3};
	int count = 0;
	FILE* fo = NULL;
	fo = fopen("input.bin", "wb");
	while (count != 15) {
		fputc(NAME[count], fo);
		count++;
	}
	fclose(fo);
}
