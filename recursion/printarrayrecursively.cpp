#include<iostream>
using namespace std;
void f(int *arr , int idx,int n){
    if(idx == n) return ;
    cout<<arr[idx]<<"\n";
    f(arr,idx+1,n);
    return ;
}
int main(){
    int n =5;
    int arr[]={6,1,9,3,4};
    f(arr,0,n);
    return 0;
}