#include<iostream>
using namespace std;
int a=5;
void fun(){
    cout<<a;
}
int main(){
    // cout<<a;
    // int p=5;
    // double p=3.5;
    // cout<<p<<"\n";
    int a=4;
    {
        int p=5,q=3;
    }
    cout<<++a;
    return 0;
}