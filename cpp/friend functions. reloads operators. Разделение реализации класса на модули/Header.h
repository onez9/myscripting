#pragma once
#include <iostream>

class Someclass {
private:
	int a;
	int b;
	int c;
public:
	Someclass(int a, int b, int c);
	void ShowAll();
	friend void func(Someclass&);


	Someclass operator + (Someclass c2) {
		return Someclass(this->a + c2.a, this->b + c2.b, this->c + c2.c);
	}
	Someclass operator - (Someclass c2) {
		return Someclass(this->a - c2.a, this->b - c2.b, this->c - c2.c);
	}
	Someclass operator * (Someclass c2) {
		return Someclass(this->a * c2.a, this->b * c2.b, this->c * c2.c);
	}
	Someclass operator / (Someclass c2) {
		return Someclass(this->a / c2.a, this->b / c2.b, this->c / c2.c);
	}


	// Перезагрузка префиксных операторов
	Someclass& operator ++ () {
		this->a++;
		this->b++;
		this->c++;
		return *this;
	}
	Someclass& operator -- () {
		this->a--;
		this->b--;
		this->c--;
		return *this;
	}
	// Перезагрузка постфиксных
	Someclass operator ++ (int) {
		Someclass current = *this;
		++* this;
		return current;
	}
	Someclass operator -- (int) {
		Someclass current = *this;
		--* this;
		return current;
	}

};


