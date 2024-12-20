#include<iostream>
using namespace std;
int sum(int *arr,int idx,int n){
    if(idx == n-1){
        return arr[idx];
    }
    return arr[idx] + sum(arr,idx+1,n);
}
int main(){
    int n=5;
    int arr[] = {2,3,5,20,1};
    int result = sum(arr,0,n);
    cout<<result<<" ";
    return 0;
}