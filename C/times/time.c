#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main() {
	srand(time(NULL));

	unsigned i;
	for (i=0;i<10;i++) {
		printf("%d ", rand() % 10);
	}
	printf("\n");
}
