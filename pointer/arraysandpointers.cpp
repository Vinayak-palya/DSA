#include<iostream>
using namespace std;
int main(){
    int arr[3] = {15,12,6};
    int *ptr = &arr[0];
    // cout<<ptr<<" "<<arr<<" " <<*ptr<<" "<<*arr<<"\n";
    cout<<*(arr+2)<<"\n";
    return 0;
}