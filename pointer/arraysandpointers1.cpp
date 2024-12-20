#include<iostream>
using namespace std;
void process(int *arr,int n){
    //inside this function we have the access of the same array as in the main
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<"\n";
    }
    *(arr+1) = 33;
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<"\n";
    }
}
int main(){
    int arr[3] = {5,1,2};
    process(arr,3);
    return 0;
}