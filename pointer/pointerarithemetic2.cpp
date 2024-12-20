#include<iostream>
using namespace std;
int main(){
    int x=10;
    int *ptr = &x;
    cout<<ptr<<"\n";
    ptr = ptr + 1;
    cout <<ptr<<"\n";
    return 0;
}