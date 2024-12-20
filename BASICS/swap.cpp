#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"a:";
    cin>>a; 
    cout<<"b:";
    cin>>b;
    int temp =a;
    a=b;
    b=temp;
    cout<<"first number is:"<<a<<endl<<"second number is :"<<b<<endl;
    // cout<<"second number is :"<<b;
    return 0;
}