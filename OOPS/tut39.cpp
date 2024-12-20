#include<iostream>
using namespace std;

class base{
    protected:
    int a;
    private:
    int b;
};
/*
                            public derivation   private derivation      protected derivation
1. private members          Not inherited       Not inherited           Not inherited 
2. protected members        protected           private                 protected
3. public members           public              private                 protected

*/




class derived : protected base{

};
int main(){
base b;
derived d;
cout<< d.a << "\n";



    return 0;
}