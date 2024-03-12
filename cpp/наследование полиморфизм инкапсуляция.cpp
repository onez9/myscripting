#include <iostream>
#include <math.h>
#include "Class.h"



class testA {
protected:
    int a1;
    int b1;
private:
    int a2;
    int b2;
public:
    void sayA() {
        using namespace std;
        cout<<"sayA"<<endl;
    }
    void show() {
        using namespace std;
        cout<<"testA"<<endl;
    }
    virtual void show_virt() {
        using namespace std;
        cout<<"testA virt"<<endl;
    }

};

class testB : public testA {
public:
    void show() {
        using namespace std;
        cout<<"testB"<<endl;
    }
    void show_virt() {
        using namespace std;
        cout<<"testB virt"<<endl;
        //cout<<a1<<" "<<b1<<endl; // переменные в секции протектед доступны для наследника класса -> success
        //cout<<a2<<" "<<b2<<endl; // в отличии от секции привате или модификатор доступа -> error
    }
};

class testC : public testB {
public:
    void show() {
        using namespace std;
        cout<<"testC"<<endl;
    }
    void show_virt() {
        using namespace std;
        cout<<"testC virt"<<endl;
        //cout<<a1<<" "<<b1<<endl; // переменные в секции протектед доступны для наследника класса -> success
        //cout<<a2<<" "<<b2<<endl; // в отличии от секции привате или модификатор доступа -> error
    }

    int cc;
};

void stack_test() {
    using namespace std;
    cout<<"stack_test() run"<<endl;
    testA a1;
    a1.show();
    a1.show_virt();
    testB b1;
    b1.show();
    b1.show_virt();
    testC c1;
    c1.show();
    c1.show_virt();
}

void head_test() {
    using namespace std;
    cout<<"head_test() run"<<endl;
    testA* a1 = new testA();
    a1->show();
    a1->show_virt();

    testB* b1 = new testB();
    b1->show();
    b1->show_virt();
    testC* c1 = new testC();
    c1->show();
    c1->show_virt();
}

void head_test1() {
    using namespace std;
    cout<<"head_test() run"<<endl;
    testA* a1 = new testC();
    a1->show();
    a1->show_virt();
    a1->testA::show_virt();
    //a1->cc = 35; // обрезалось -> error

    testB* b1 = new testC();
    b1->show();
    b1->show_virt();
    //b1->cc = 35; // обрезалось -> error

    testC* c1 = new testC();
    c1->show();
    c1->show_virt();
    c1->cc = 35; 
    /*
    c1->testA::show();
    c1->testB::show();
    c1->testC::show();
    */





    /*
    int arr[10] = {1, 2, 3, 4};
    for(const auto item : arr) {
        cout<<item<<endl;
    }
    */
}


class cla1 {
public:
    int tmp1;
    void say() {
        using namespace std;
        cout<<"say"<<endl;
    }
    cla1() {
        using namespace std;
        cout<<"cla1: i'm born!"<<endl;
    }

};

class cla2 : protected cla1{
public:
    int tmp2;
    cla2() {
        using namespace std;
        cout<<"cla2: i'm born!"<<endl;
    }

};

class cla3 : protected cla2{
public:
    int tmp3;
    cla3() {
        using namespace std;
        cout<<"cla3: i'm born!"<<endl;
        say(); // protected - внутри класса наследника работает, как надо
    }

};

int main() {
    using namespace std;
    cla3 cl3; // срабатывают все три конструктора
    cla3* heapcl3 = new cla3();
    //cl3.tmp1 = 1; //
    //cl3.tmp2 = 2;
    cl3.tmp3 = 3;
    //cl3.say(); // вне класса наследника или родителя не работает

    return 0;
}


