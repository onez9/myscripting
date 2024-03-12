#include <stdio.h>
#define YEAR0 1
struct date{
	unsigned short day : 3;
	unsigned short month : 1;
	unsigned short year : 1;
	unsigned int a : 1;
	int c1: 1;
};
void main(){
	struct date today;
	today.day = 1;
	today.month = 1;
	today.a = 1;
	today.c1 = 1;
	today.year = 1 - YEAR0;
	printf("\n Сегодня %u.%u.%u \n", today.day, today.month, today.year + YEAR0);
	printf("\n Размер структуры today : %d байт", sizeof(today));
	printf("\n Значение элемента today = %hu = %hx шестн.\n", today, today);
}
