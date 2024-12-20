#include<iostream>
using namespace std;

class complex;

class calculator{
    public:
    int add(int a,int b){
        return a + b;
    }
    int sumrealcomplex(complex ,complex );
    int sumcompcomplex(complex ,complex );

};
class complex{
    int a;
    int b;
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);
    // friend int Calculator ::sumCompComplex(Complex, Complex);
    // alternate way is :Declaring the entire class as friend calss
    friend class calculator;
    public:
    void setdata(int n1,int n2){
        a = n1;
        b = n2;
    }
    void display(){
        cout<< "your complex number is:"<<a<<"+ i"<<b<<"\n";
    }
};
int calculator :: sumrealcomplex(complex c1,complex c2){
        return c1.a + c2.a;
    }
int calculator :: sumcompcomplex(complex c1,complex c2){
        return c1.b + c2.b;
    }

int main(){
    complex c1,c2,c3;
    c1.setdata(1,2);
    c2.setdata(3,4);
    calculator calc;
    int resr = calc.sumrealcomplex(c1,c2);
    cout<<"the sum of the real part of the complex number is:"<<resr<<endl;
    int resc = calc.sumcompcomplex(c1,c2);
    cout<<"the sum of the imaginary  part of the complex number c1 and c2 is "<<resc<<"\n";

    return 0;
}