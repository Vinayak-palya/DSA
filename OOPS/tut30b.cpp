#include<iostream>
using namespace std;


class point{
    int x,y;
    public:
    point(int a,int b){
        x = a;
        y = b;
    }
    void display(){
    cout<<"The given point is :"<<"("<<x <<  " , "<< y << ")"<<endl;
    }
};


int main(){


    point p1(3,4);
    p1.display();
    point p2 = point(5,6);
    p2.display();

    return 0;
}