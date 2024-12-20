#include<iostream>
using namespace std;
/*
Case1:
class B: public A{
   // Order of execution of constructor -> first A() then B()
};

Case2:
class A: public B, public C{
    // Order of execution of constructor -> B() then C() and A()
};

Case3:
class A: public B, virtual public C{
    // Order of execution of constructor -> C() then B() and A()
};

*/

class B1{
    int data1;
    public:
    B1(int i){
        data1 = i;
        cout << "Base 1 constructor is called : " << "\n";
    }
    void printdata1(){
        cout << "The value of data 1 is " << data1 << "\n";
    }

};
class B2{
    int data2;
    public:
    B2(int j){
        data2 = j;
        cout << "Base 2 constructor is called : " << "\n";
    }
    void printdata2(){
        cout << "The value of data 2 is " << data2 << "\n";
    }
};
class derived : public B2,public B1{
    int d1,d2;
    public:
    derived(int a,int b,int c,int d) : B1( a) , B2( d){
        d1 = c;
        d2 = d;
        cout << "Derived class constructor is called." << "\n";
    }
    void printdataderived(){
        cout << "The value of data derived are" << d1 << "  " << d2 << "\n";
    }
};
int main(){
    derived o(1,2,3,4);
    o.printdata1();
    o.printdata2();
    o.printdataderived();

    return 0;
}