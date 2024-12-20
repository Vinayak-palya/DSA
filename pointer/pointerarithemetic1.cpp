#include<iostream>
using namespace std;
int main(){
    int x = 20;
    int *ptr = &x;
    double dec=9.8;
    cout<<sizeof(dec)<<"\n";
    double *ptrd = &dec;
    cout<<sizeof(x)<<"\n";
    cout<<ptr<<" "<<(ptr-1)<<"\n";
    cout<<ptrd<<" "<<(ptrd+2)<<"\n";
    return 0;
}