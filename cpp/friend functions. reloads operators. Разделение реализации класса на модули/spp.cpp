#include <iostream>
#include <thread>
#include <csignal>
#include "Header.h"

using namespace std;


void signal_handler(int signum) {
	cout << "Interrupt signal (" << signum << ") received." << endl;
	exit(signum);
	



}


void func() {
	int acc = 0; 
	signal(SIGINT, signal_handler);
	while (1) {
		acc++;
		//if (acc % 3 == 0) cout << endl;
		cout << this_thread::get_id << " " << acc << endl;
		this_thread::sleep_for(chrono::milliseconds(300));
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	Someclass SObj1(1, 2, 3);
	Someclass SObj2(1, 2, 3);

	SObj1.ShowAll();
	SObj2.ShowAll();

	Someclass SObjAdd = SObj1 + SObj2;
	SObjAdd.ShowAll();

	Someclass SObjSub = SObj1 - SObj2;
	SObjSub.ShowAll();

	Someclass SObjMut = SObj1 * SObj2;
	SObjMut.ShowAll();

	Someclass SObjDiv = SObj1 / SObj2;
	SObjDiv.ShowAll();

	cout << "---" << endl;
	Someclass SObjInc = SObj1++;
	SObjInc.ShowAll();
	SObj1.ShowAll();

	cout << "---" << endl;
	func(SObj1);


	cin.get();
	return 0;

}

