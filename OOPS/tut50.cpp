#include<iostream>
using namespace std;



int main(){
    // Basic example

    int a = 11;
    int* ptr = &a;
    cout<<"the value of a is "<<*ptr<<"\n";

    // new keyword
    float *p = new float(40.28);
    // delete p;
    cout<<"the value at address  p is " << *p<< "\n";

    int *arr = new int [3];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    cout << "the value of arr[0] is " << arr[0]<<"\n";
    cout << "the value of arr[1] is " << *(arr + 1) << "\n";
    cout << "The value of arr[2] is " << arr[2] << "\n";

    // Delete keyword;
    
    int *brr = new int [3];
    
    brr[0] = 0;
    brr[1] = 1;
    brr[2] = 2;
    delete [] brr;
    cout << "the value of brr[0] is " << brr[0]<<"\n";
    cout << "the value of brr[1] is " << *(brr + 1) << "\n";
    cout << "The value of brr[2] is " << brr[2] << "\n";
    return 0;
}