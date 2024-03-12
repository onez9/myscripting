#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;


double add(double a, double b) {
    return a+b;
}

double sub(double a, double b) {
    return a-b;
}

double mut(double a, double b) {
    return a*b;
}

double div(double a, double b) {
    return a/b;
}

int testFunctionWithFunction(double a, double b, double (*somefunction) (double, double)) {
    cout << "Function is running" << endl;
    return somefunction(a, b);
}


namespace n1 {
    int add1(int a, int b) {
        return a+b;
    }
}


namespace n2 {
    double add2 (double n1, double n2) {
        return n1 + n2;
    }
}


class car {
    public:
    int a;
    int b;
    int c;
    public:
    void show() {
        cout<<a<<" "<<b<<" "<<c<<endl;
    }

};

class animal {
    public:
    int a;
    int b;
    int c;
    public:
    void show() {
        cout<<a<<" "<<b<<" "<<c<<endl;
    }

};

class bu {
private:
    float x;
    float y;
    float z;

public:
    bu(){
        cout<<"start"<<endl;
    }
    bu(float x, float y, float z) {
        cout<<"Class is created"<<endl;
        this->x=x;
        this->y=y;
        this->z=z;
    }
    ~bu() {
        /*
        using std::chrono::system_clock;
        cout<<"Object is destroy"<<endl;

        std::time_t tt = system_clock::to_time_t (system_clock::now());

        struct std::tm * ptm = std::localtime(&tt);

        std::cout << "Current time: " << std::put_time(ptm,"%X") << '\n';
        std::cout << "Waiting for the next minute to begin...\n";

        ++ptm->tm_min; ptm->tm_sec=0;

        //this_thread::sleep_for(chrono::milliseconds(432));
        //this_thread::sleep_until(chrono::system_clock::from_time_t(mktime(ptm)));
        */
        cout<<"end"<<endl;
    }
    void showAll() {
        cout<<"x="<<x<<endl;
        cout<<"y="<<y<<endl;
        cout<<"z="<<z<<endl;

    }
};

int main()
{
    m1:
    bu* b1=new bu(123, 54, 543);
    b1->showAll();

    //bu* b2 = new b1[10];
    int num = 10;
    bu **b2 = new bu*[num];
    for (int i=0;i<num;i++){
        b2[i]=new bu(i,i,i);
        b2[i]->showAll();

        cout<<endl;
    }


    for (int i=0;i<num;i++){
        cout << i<<endl;
        delete b2[i];
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    goto m1;



    /*
    car a1;
    a1.a = 3;
    a1.b = 34;
    a1.c = 34;

    a1.show();
    std::cout<<(43<<3)<<std::endl;
    cout << n1::add1(3, 3) << endl;
    cout << n2::add2(3345, 34) << endl;


    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    int a;
    cout<<"Type something number: "<<endl;
    cin >> a;
    double (*show_message) (double, double);
    printf("%s, %i", "somestring", 43);

    show_message = add;


    int result = show_message(3, 53);


    cout << result << endl;

    cout << testFunctionWithFunction(33, 234, add) << endl;
    cout << testFunctionWithFunction(33, 234, sub) << endl;
    cout << testFunctionWithFunction(33, 234, mut) << endl;
    cout << 33.0 / 0.0 << endl;
    */

    cin.get();
    return 0;
}
