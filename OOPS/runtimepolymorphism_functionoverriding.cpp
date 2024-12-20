#include<iostream>
using namespace  std;

class parent{
        public:
        virtual void print(){
            cout<<"parent class"<<"\n";
        }
        void show(){
            cout<<"parent class"<<"\n";
        }
    };
    class child:public parent{
    public:
        void print(){
            cout<<"child class"<<"\n";
        }
        void show(){
            cout<<"child class"<<"\n";
        }
    };
int main(){
    parent *p;
    child c;
    p = &c;
    p->print();
    p->show();

    return 0;
}