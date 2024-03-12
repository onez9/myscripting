#include <stdio.h>

void main() {
	FILE* fo;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	//printf("%#x\n", string);
	//printf("%#x\n", &string);
	//prntf("%s\n", string);
	int n = 15;
	fo = fopen("output.bin", "wb");
	// write to file
	fwrite(arr, sizeof(int), 10, fo);
	fclose(fo);

}
