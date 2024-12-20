#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
    complex(int ,int);
    complex(int);
    complex();
    void print(){
        cout<<"the given complex number is :"<< a <<"+"<<b<<"i"<<endl;
    }
};

complex :: complex(int x,int y){
    a = x;
    b = y;

}
complex :: complex(int x){
    a = x;
    b = 0;

}
complex :: complex(){
    a = 0;
    b = 0;
}




int main(){

complex c1(3,4);
c1.print();
complex c2(3);
c2.print();
complex c3;
c3.print();


    return 0;
}