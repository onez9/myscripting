#include <stdio.h>
void butler();
void main() {
	/*
	printf("СИ-программой. \n");
	int o = 255;
	o++;
	--o;
	printf("Hello my friend!\b\b\n");
	printf("%d\n", o);
	butler();
	double num = 10212312;
	printf("%e\n", num);
	printf("%E\n", num);
	printf("\n\n%#d\n\n", o);
	int a = printf("%i\n", o);
	printf("\n\n%#x\n\n", o);
	printf("%d", a);
	float fnum = 1.23456789;
	printf("%-1.4f\n", fnum);
	a = printf("%-10.4f\n", fnum);
	int b = printf("%-10d", 35); 
	printf("%-1.4f\n", fnum);
	printf("%-1.4f\n", fnum);
	printf("%-1.4f\n", fnum);
	printf("%-1.4f\n", fnum);
	printf("%-1.4f\n", fnum);

	printf("%d", a);
	printf("%d", b);
	printf("\n%-5.10s\n", "hello world");
	*/
	//int num;
	//scanf("%d", &num);
	//printf("num %d\n", num);
	char arr[10];
	scanf("%s", arr);
	for (int i=0;i<10;i++) {
		printf("%c\n", arr[i]);
	}


	
}
void butler(){
	printf("Hello world!");
}
