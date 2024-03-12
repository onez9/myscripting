#include "Header.h"



void Someclass::ShowAll() {
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
}

Someclass::Someclass(int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

void func(Someclass& sc) {
	using namespace std;
	cout << sc.a << " " << sc.b << " " << sc.c << endl;
}