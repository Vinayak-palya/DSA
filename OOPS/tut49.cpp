#include<iostream>
using namespace std;

/*
Syntax for initialization list in constructor:
constructor (argument-list) : initilization-section
{
    assignment + other code;
}
*/
class Test{
    int a;
    int b;
    public:
    // Test(int i,int j) : a(i) , b(j + a)
    // Test(int i ,int  j) : a(i ), b(i+j)
    // Test(int i ,int  j) : b(i), a(b+j)  this will create a problem
    Test(int i ,int  j) : a(i ), b(j)
    {
        cout<<"the constructor is called."<<"\n";
        cout <<"the value of a is "<<a<<"\n";
        cout<<"the value of b is "<< b<<"\n";
    }
};
int main(){
    Test t(4,6);


    return 0;
}