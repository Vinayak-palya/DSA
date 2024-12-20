#include<iostream>
using namespace std;
int main(){
    int a=4;
    cout<<sizeof(a)<<endl;
    char name='a';
    cout<<sizeof(name)<<endl;
    bool flag;
    a==name?flag=true:flag=false;
    cout<<flag<<endl;
    cout<<(&a)<<endl;
    a=6;
    cout<<(a++)<<endl;
    int b=5;
    cout<<(--b)<<endl;
    cout<<a<<endl;
    // cout<<(4+2) + cout<<"pqr"<<endl;
    return 0;
}