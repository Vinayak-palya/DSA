#include<iostream>
using namespace std;
int main(){
    // int arr[]={1,2,3,4};
    // // cout<<sizeof(arr)<<endl<<(sizeof(arr)/sizeof(arr[0]))<<endl;
    // int size=sizeof(arr)/sizeof(arr[0]);
    // //for loop
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<endl;
    // }
    // //for each loop
    // for(int ele:arr){
    //     cout<<ele<<endl;
    // }
    // //while loop
    // int index=0;
    // while(index<size){
    //     cout<<arr[index]<<endl;
    //     index++;
    // }
    char vowels[5];
    // for(int idx=0;idx<5;idx++){
    //     cin>>vowels[idx];
    // }
    for(char &elements:vowels){
        cin>>elements;
    }
    for(int idx=0;idx<5;idx++){
        cout<<vowels[idx]<<" ";
    }
    return 0;
}