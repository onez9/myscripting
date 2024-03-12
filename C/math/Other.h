int euc1(int a, int b) {
	int c;
	while(true) { 
		if (a > b) {
			if (a % b == 0) {
				return b;
			}
			c = b;
			b = a % b;
			a = c;
		} else if (a < b) {
			if (b % a == 0) {
				return a;
			}
			c = a;
			a = b % a;
			b = c;
		} else {
			return a;
		}
	}
}
int euc2(int a, int b) {
	int c;
	while (true) {
		if (a != 0 && b != 0) {
			if (a > b) {
				a = a % b;
			} else {
				b = b % a;
			}
		} else {
			return a+b;
		}
	}
}

int* sort(int* arr) {
	:
}


