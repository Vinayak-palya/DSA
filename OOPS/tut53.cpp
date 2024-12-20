#include<iostream>
using namespace std;
class A{
    int a;
    public:
    // void setdata(int a){
    //     this->a = a;

    // }
    A& setdata(int a){
        this->a = a;
        return *this;
    }
    void getdata(){
        cout<<"The value of a is "<< a <<"\n";
    }

};

int main(){
    //this  is a key word which is a pointer  which points to an object which invokes the member function.
    A a;
    // a.setdata(4);
    // a.getdata();
    a.setdata(4).getdata();
    return 0;
}

