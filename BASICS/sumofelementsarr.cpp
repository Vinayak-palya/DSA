#include<iostream>
using namespace std;
int main(){
    int arr[]={3,4,10,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}