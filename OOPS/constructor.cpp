#include<iostream>
using namespace std;
class rectangle{
    public:
    int L;
    int B;
    rectangle(){//default constructor - no args passed
        L = 0;
        B = 0;

    }
    rectangle(int x,int y){//parameterized constructor - args passed
        L = x;
        B = y;
    }
    rectangle(rectangle &r){//copy constructor - initialize an object by another existing object
        L = r.L;
        B = r.B;
    }
    ~rectangle(){
        cout<<"destructor is called"<<endl;
    }
};

int main(){
    rectangle* r1 = new rectangle();
    cout<<r1->L<<" "<<r1->B<<"\n";
    delete r1;
    rectangle r2(3,4);
    cout<<r2.L<<" "<<r2.B<<"\n";
    rectangle r3 = r2;
    cout<<r3.L<<" "<<r3.B<<" ";
    return 0;
}