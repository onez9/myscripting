#include <stdio.h>

void main() {
	int a;
	int b;
	int c;
	printf("%#X %#X %#X\n", &a, &b, &c);
	a = 771; b = 22; c = 323;
	printf("%#X\n%#X\n%#X\n", a, b, c);
	printf("%#X %#X %#X\n", &a, &b, &c);
	int arr[3] = {1,2,4};
	printf("%#X\n%#X\n%#X\n", &arr[0], &arr[1], &arr[2]);

}
