#include<iostream>
using namespace std;
class complex{
    int a;
    int b;
    friend complex sumcomplex(complex c1,complex c2);
    public:
    void setdata(int n1,int n2){
        a = n1;
        b = n2;
    }
    void display(){
        cout<<"The required complex number is:"<<a<<"+ i"<<b<<"\n";
        }
};
complex sumcomplex(complex c1,complex c2){
    complex c3 ;
    c3.setdata((c1.a + c2.a) , (c1.b + c2.b));
    return c3;
}

int main(){
complex c1,c2,sum;
c1.setdata(3,4);
c1.display();

c2.setdata(3,4);
c2.display();

sum = sumcomplex(c1,c2);
sum.display();
    return 0;
}
/*
friend function properties 
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contains the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/