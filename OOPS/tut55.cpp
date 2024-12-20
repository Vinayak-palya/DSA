#include<iostream>
using namespace std;
class BaseClass{
    public :
    int var_base;
    void display(){
        cout << "The value of the variable of the base class is : " << var_base<<"\n";
    }
};
class Derived: public BaseClass{
    public :
    int var_Derived;
    void display(){
        cout << "The value of the variable of the base class is : " << var_base<<"\n";
        cout << "The value of the variable of the derived class is :" << var_Derived << "\n";
    }
};
int main(){
    BaseClass * pointer_base;
    BaseClass obj_base;
    Derived obj_derived;
    pointer_base = &obj_derived;//pointing Base class pointer to derived class


    pointer_base->var_base = 34;
    // pointer_base->var_derived = 100;  // Will throw an error
    pointer_base->display();


    pointer_base->var_base = 3400;
    pointer_base->display();
    Derived *pointer_derived;
    pointer_derived = &obj_derived;
    pointer_derived->var_base = 9442;
    pointer_derived->var_Derived = 98;
    pointer_derived->display();

    return 0;

}