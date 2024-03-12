#include <stdio.h>

//inline int fun(int a, int b) __attribute__((always_inline));

//void fuck();
//void func() {
	//int a = 3+4;
//}
void swap(int*, int*);
void func(int*, int*);
void main() {
	//int res = fun(2, 4);
	//printf("%d\n", res);
	//getchar();
	int b = 3;
	int a = 2;
	printf("%d\t%d\n", a, b);
	swap(&a, &b);
	printf("%d\t%d\n", a, b);
}
void swap(int* a, int* b) {
	*a = *b - *a;
	*b = *b - *a;
	*a = *b + *a;
}
//void fuck() {
	//printf("Fuck you!\n");
//}






/*
inline int fun(int a, int b) {
	return a+b;
}
*/
