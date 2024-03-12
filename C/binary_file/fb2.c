#include <stdio.h>






//size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
//size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );


void main() {
	FILE* fo = NULL;
	fo = fopen("output.bin", "wb");
	int str[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = fwrite(str, sizeof(int), 12, fo);
	printf("%d\n", n);
	fclose(fo);

	int arr[9];
	fo = fopen("output.bin", "rb");
	// read
	fread(arr, sizeof(int), 9, fo);
	printf("%d\n", arr[6]);
	fclose(fo);
	printf("----\n");
	for (int i=0;i<9;i++) {
		printf("%d\n", arr[i]);
	}

	//int fseek ( FILE * stream, long int offset, int origin );
	//seek_set start
	//seek_cur current position
	//seek_end end

	fo = NULL;
	fo = fopen("output.bin", "w+b");
	fwrite(str, sizeof(int), 10, fo);
	int a[10];
	int b[10];
	fseek(fo, 0, SEEK_SET);
	fread(a, sizeof(int), 9, fo);
	// ---
	printf("hello world!\n");
	for(int i=0;i<9;i++) {
		printf("%d\n", a[i]);
	}
	fseek(fo, 2, SEEK_CUR);
	fread(b, sizeof(int), 9, fo);
	for(int i=0;i<9;i++) {
		printf("%d\n", b[i]);
	}
	fclose(fo);

}
