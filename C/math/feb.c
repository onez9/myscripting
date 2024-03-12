#include <stdio.h>
#include <stdbool.h>

int feb(int number) {
	if (number == 1 || number == 0) {
		return 1;
	} else {
		return feb(number - 1) + feb(number - 2);
	}
}

// 1 1 2 3 5 8
void main() {
	int n = 0;
	
	bool sex = false;
	while (sex) {
		printf("%d\n", feb(n));
		n++;
	}

	long long n1, n2, n3;
	n1 = n2 = 1;
	while (true) {
		n3 = n1 + n2;
		if (n3 < 0) break;
		printf("%llu\n", n3);
		n1 = n2;
		n2 = n3;
	}
	
	
}
