#include<iostream>
using namespace std;
int main(){
    int arr[3] = {11,12,13};
    int (*p)[3] = &arr;
    

    cout<<p<<" "<<arr<<" "<<*p<<" "<<*arr<<"\n";
    return 0;
}