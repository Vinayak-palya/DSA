#include<iostream>
using namespace std;
int main(){
    int x = 18;
    float  y = 7.9;
    // cout<< &x << " " << &y;
    //create a pointer that can store the address of x;
    //as x is an integer  , so we need a pointer that can store address of integer type
    int *ptr = &x;
    cout<<"address stored in the pointer"<<ptr<<endl;
    cout<< "value present at the address:"<<*ptr<<" "<<"\n";
    float *ptr2 = &y;
    cout<< ptr2<<" ";
    x=23;
    *ptr=50;
    cout<<"the value of x"<<x;
    
    
    return 0;
}