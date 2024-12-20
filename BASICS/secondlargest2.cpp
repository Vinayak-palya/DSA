#include<iostream>
using namespace std;
int secondlargest(int arr[],int size){
    int max =INT_MIN;
    int secondmax=max;  
    for(int i=0;i<size;i++){
        if(arr[i]>max) max=arr[i];
    }
    for(int j=0;j<size;j++){
        if(arr[j]>secondmax && arr[j]!=max){
            secondmax=arr[j];
        }
    }
    return secondmax;
}

int main(){
    int arr[]={2,3,5,7,6,1,7};
    int n=7;
    cout<<secondlargest(arr,n)<<"\n";
    return 0;
}