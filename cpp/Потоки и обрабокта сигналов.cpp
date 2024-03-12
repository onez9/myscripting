#include <iostream>
#include <thread>
#include <csignal>


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

class Someclass {
private:
	int a;
	int b;
	int c;
public:
	Someclass(int a) {
		this->a = a;
	}

	Someclass operator + (Someclass c2) {
		return Someclass(this->a + c2.a);
	}
};


int main()
{
	signal(SIGINT, signal_handler);
	
	
	
	thread t1(func);
	
	int acc = 0;
	while (1) {
		acc++;
		cout <<	this_thread::get_id << " main " << acc << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
	}
	t1.join();
	system("pause");
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
