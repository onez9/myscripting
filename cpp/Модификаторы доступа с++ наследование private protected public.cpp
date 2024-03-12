#include <iostream>
#include <string>


using namespace std;

class A {
public:
    string s1 = "one";
    A() {
        cout << "start A class" << endl;
    }
    ~A() {
        cout << "end A class" << endl;
    }
private:
    string s2 = "two";
protected:
    string s3 = "three";
};


class B : public A
{
public: 
    B() {
        cout << "start B class" << endl;
    }
    ~B() {
        cout << "end B class" << endl;
    }
    void show() {
        cout << s1 << endl; // s2 недоступна тут при любом наследовании
        // cout << s2 << endl; // s2 недоступна тут при любом наследовании
        cout << s3 << endl; // s2 недоступна тут при любом наследовании

    }

};

int main()
{
    B b1;
    b1.show();
    
    cout << "s1: " << b1.s1 << endl; // При наследовании public, тут может быть доступно
    //cout << "s2: " << b1.s2 << endl; // нет доступа при любом наследовании
    //cout << "s3: " << b1.s3 << endl; // нет доступа при любом наследовании
    
    return 0;
}
