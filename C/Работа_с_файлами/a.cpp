#include <iostream>

int main() {
	const char* arr[2];
	char* arr[0] = new char[10];
	char* arr[1] = new char[10];
	arr[0] = "hello";
	arr[1] = "world";
	return 0;
}
