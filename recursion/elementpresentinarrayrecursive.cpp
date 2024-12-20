#include<iostream>
using namespace std;
bool f(int *arr,int n,int i,int x){
    if( i == n ){
        return false;
    }
  return (arr[i] == x) || f(arr,n,i+1,x);
}
int main(){
    int arr[] = {5,4,1,8,6,-9,8,2,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin>>x;
    bool flag = f(arr,n,0,x);
    if(flag) cout<<"yes";
    else  cout<<"no";
    return 0;
} 