#include<iostream>
using namespace std;
int maximum(int *arr,int idx,int n){
    
    if(idx == n-1) return arr[idx];
    return max(arr[idx],maximum(arr,idx+1,n));
}
int main(){
    int n = 5;
    int arr[]={3,10,2,5,3};
    int max = maximum(arr,0,n);
    cout<<max<<" ";
    return 0;
}