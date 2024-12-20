#include<iostream>
using namespace std;
int main(){
    float f = 10.2;
    int x = 0;
    void *ptr = &f;
    ptr = &x;
    int *integerpointer = (int *)ptr;
    cout<<*integerpointer;
    return 0;
}