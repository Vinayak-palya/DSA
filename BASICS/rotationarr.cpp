#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=5;

    int k=3;
    k%=n;
    int ansarr[5];
    int j=0;
    for(int i=n-k;i<n;i++){
        ansarr[j++]=arr[i];
    }
    for(int i=0;i<=k;i++){
        ansarr[j++]=arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<ansarr[i]<<" ";
    }

    return 0;
}