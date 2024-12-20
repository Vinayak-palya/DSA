#include<iostream>
using namespace std;
void change(int &z){
    z=100;
}

int main(){
    // int p=5;
    // int &q=p;
    // q++;
    // cout<<&p<<endl<<&q<<endl;
    int a=5;
    change(a);
    cout<<a;
    return 0;
}