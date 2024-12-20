#include<iostream>
using namespace std;
int main(){
    int x,y;//declare x and Y so that have garbage values
    cin>>x>>y;//taking input of x and y
    int *ptrx=&x;
    int *ptry = &y;
    int result;
    int *ptrr = &result;
    *ptrr = *ptrx + *ptry;
    cout<<result;
    cout<<&ptrr;
    return 0;
}