#include<iostream>
using namespace std;
int main(){
    int arr[2]={1,19};
    int *ptr = &arr[0];
    cout<<ptr<<" "<< *ptr<<"\n";
    cout<<(ptr+1)<<" "<< *(ptr+1)<<endl;
    cout<<*ptr++<<"\n";
    cout<<arr[0]<<" "<<arr[1]<<"\n";
    cout<<ptr<<" "<<*ptr<<"\n";

    return 0;
}