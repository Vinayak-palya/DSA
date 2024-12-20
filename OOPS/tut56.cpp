#include<iostream>
using namespace std;

class BaseClass{
    public :
    int var_base = 100;
    virtual void display(){
        cout << "1 The value of the variable of the base class is : " << var_base<<"\n";
    }
};
class Derived: public BaseClass{
    public :
    int var_Derived = 200;
     void display(){
        cout << "2 The value of the variable of the base class is : " << var_base<<"\n";
        cout << "2 The value of the variable of the derived class is :" << var_Derived << "\n";
    }
};
int main(){
    BaseClass *pointer_Base;
    Derived obj_derived;
    pointer_Base = &obj_derived;
    pointer_Base->display();

    return 0;
}