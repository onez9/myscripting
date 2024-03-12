#include <cstdio>
#include <iostream>
#include <filesystem> // C++17
//#include <iterator>
#include <ostream>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <string> 
#define pi 3.1415926535
#include <iostream>

class Point
{
public:
    Point(double x, double y, double z)
    {
        this->X=x;
        this->Y=y;
        this->Z=z;
    }

    bool operator==(const Point& point) const=default;
    bool operator!=(const Point& point) const=default;

    double X;
    double Y;
    double Z;



};

class Vector{
public:
    Vector(double x, double y, double z){
        this->X=x;
        this->Y=y;
        this->Z=z;
    }
    ~Vector(){
        //std::cout<<"Сработал деструктор у класса вектор. \n";
    }

    Vector& operator+=(const Vector& vector){
        X+=vector.X;
        Y+=vector.Y;
        Z+=vector.Z;
        return *this;
    }
    Vector& operator-=(const Vector& vector){
        X-=vector.X;
        Y-=vector.Y;
        Z-=vector.Z;
        return *this;
    }

    Vector operator-() const{
        return Vector{-X,-Y,-Z};
    }

    std::string get_coords() const {
        return "X: "+std::to_string(X)+"; Y: "+std::to_string(Y)+"; Z: "+std::to_string(Z);

    }

    double X;
    double Y;
    double Z;

    void show_coords(){
        std::cout<<"print vector"<<std::endl;
        std::cout<<"x: "<<X<<"; y: "<<Y<<"; z: "<<Z<<std::endl;
    }

};

Vector 
operator+(const Point& p1, const Point& p2)
{

    return Vector(p2.X - p1.X, p2.Y - p1.Y, p2.Z - p1.Z);

}

//Vector operator+=(Vector& v1, const Vector& v2){
//    v1.X+=v2.X;
//    v1.Y+=v2.Y;
//    v1.Z+=v2.Z;
//    return v1;
//}

Vector 
operator+(const Vector& v1, const Vector& v2)
{
    return Vector(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
}

Vector 
operator-(const Vector& v1, const Vector& v2)
{
    return Vector(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
}

double 
get_scalar_product(const Point& p1, const Point& p2)
{
    double result = p1.X*p2.X + p1.Y*p2.Y + p1.Z*p2.Z;
    return result;

}

double 
get_distance(const Point& p1, const Point& p2)
{
    try
    {
        double result = sqrt(pow(p2.X-p1.X, 2) + pow(p2.Y-p1.Y, 2) + pow(p2.Z-p1.Z, 2));
        return result;
    }
    catch(...)
    {
        std::cout<<"some error"<<std::endl;
        return -1;
    }
}

double 
get_angle(const Vector& v1, const Vector& v2)
{
    double result = (v1.X*v2.X + v1.Y*v2.Y + v1.Z*v2.Z) / (sqrt(v1.X*v1.X + v1.Y*v1.Y + v1.Z*v1.Z) * sqrt(v2.X*v2.X + v2.Y*v2.Y + v2.Z*v2.Z));
    result = acos(result)*180/pi;
    return result;
}

std::ostream& 
operator<<(std::ostream& stream, const Vector& vector)
{
    //stream<<"Value: ";
    stream<<vector.get_coords();
    return stream;
}



class myOutput{
public:
    template<typename T>
    myOutput& operator<<(const T& value){
        std::cout<<value<<" ";
        return *this;

    }

};




int 
main(int argc, char** argv)
{
    using namespace std;
    cout << "Программа для вычисления угла между 2-мя векторами." << endl;
    cout << "run:" << "\n";


    cout<<"\n";

    //Point p1(0,0,0);
    //Point p2(3,3,3);
    //Point p3(3,3,3);
    //Point p4(4, 3, 8);
    //Vector v1=p1+p2;
    //v1.show_coords();
    Vector v1{3,3,0};
    Vector v2{3,1,0};
    //v2.show_coords();
    //v1+=v2;
    //v1-=v2;
    //v1-=v2;
    //v1.show_coords();
    //cout<<(p1==p3)<<endl;
    //cout<<(p2==p3)<<endl;
    //cout<<(p1!=p3)<<endl;
    //cout<<get_distance(p1, p4)<<endl;






    cout<<get_angle(v1, v2)<<endl;
    cout<<v1<<endl;
    cout<<v2<<endl;
    Vector v4=-v2;
    cout<<v4<<endl;
    cout<<get_angle(v1, v4)<<endl;
    myOutput mo1;
    mo1<<123<<"hello world"<<2.234;
    
    return 0;




}





