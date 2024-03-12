#include <stdio.h>
#include <math.h>

void main() {
	void* p;
	int a = 44;
	p = &a;
	printf("%d \n", *((int*)p));
	//printf("%d \n", *p);
	printf("0 && 0 = %d\n", 0 && 0);
	printf("1 && 0 = %d\n", 1 && 0);
	printf("0 && 1 = %d\n", 0 && 1);
	printf("1 && 1 = %d\n", 1 && 1);
	printf("0 & 0 = %d\n", 0 & 0);
	printf("1 & 0 = %d\n", 1 & 0);
	printf("0 & 1 = %d\n", 0 & 1);
	printf("1 & 1 = %d\n", 1 & 1);
	printf("%d\n", ~1);
	const char* p1 = NULL;
	unsigned lenght = 0;
	char world[] = "Hello!";

	p1 = world;
	printf("\n");
	while (*(p1++)) {
		printf("%c ", *p1);
		lenght++;
	}
	printf("\n");
	printf("lenght(\"%s\") = %d\n", world, lenght);
	printf("%#X\n", p1);
	const int a1 = 2;
	char arr3[] = "hello world ";
	int count = 0;
	unsigned i = 0;
	while (arr3[i++] != '\0') {
		count++;
	}
	printf("%d\n", count);
	char string[128];
	scanf("%5s", string);
	printf("%s\n", string);
	char arr123[4] = {'H', 'e', 'l', 'l'};
	unsigned len = 0;
	while (arr123[len]) {
		len++;
	}
	printf("%s\n", arr123);
	printf("%d\n", len);
	printf("%d\n", sizeof(size_t));
	size_t tr = 100;
	tr -= 200;
	printf("%zu\n", tr);
}
