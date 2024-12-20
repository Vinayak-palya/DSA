#include<iostream>
using namespace std;
float circumference(int r){
    return 2*3.14*r;
}
float area(int r){
    return 3.14*r*r;
}
int main(){
    int r;
    cin>>r;
    float circleA=area(r);
    float circleC=circumference(r);
    cout<<"area is:"<<circleA<<" "<<"circumfernce is :"<<circleC;

    return 0;
}