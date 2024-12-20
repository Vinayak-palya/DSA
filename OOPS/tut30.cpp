#include<iostream>
using namespace std;


class complex{
    int a,b;
    public:
    complex(int ,int );//constructor declaration;
    void printdata(){
        cout<<"the given complex number is:" << a << " + " << b << " i "<< endl;;
    }
};
complex :: complex(int x,int y){ //this is the parameterized constructor as it takes two parameters
    a = x;
    b = y;
}


int main(){

    //Implicit call
    complex c1(3,4);
    c1.printdata();

    // Explicit call;
    complex c2 = complex(5,6);
    c2.printdata();

    return 0;
}