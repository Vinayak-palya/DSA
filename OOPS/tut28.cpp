#include<iostream>
using namespace std;
class Y;

class X{
int data1;
friend int sum(X,Y);
public:
void setdata(int val){
    this->data1 = val;
}
};
class Y{
 int data2;
 friend int sum(X,Y);
 public:
 void getdata(int val){
    this->data2 = val;
 }

};
int sum(X m1,Y m2){
    return m1.data1 + m2.data2;
}



int main(){
    X m1;
    Y m2;
    m1.setdata(3);
    m2.getdata(5);
    int res = sum(m1,m2);
    cout<<res<<"\n";
    return 0;
}