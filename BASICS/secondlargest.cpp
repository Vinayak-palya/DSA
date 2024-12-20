#include<iostream>
using namespace std;
int largest(int arr[],int size){
    int max=INT_MIN;
    for(int i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int arr[]={2,3,5,7,6,1};
    int size=6;
    int max=largest(arr,size);
    for(int i=0;i<size;i++){
        if(arr[i]==max) arr[i]=INT_MIN; 
    }
    // int secondlargest;       --> 1st method
    // int max2=-1;
    // for(int i=0;i<size;i++){
    //     if(arr[i]>max2){
    //         max2=arr[i];
    //     }
    // }
    // cout<<max2<<" is the second largest element of an given array";
    int secndlargest=largest(arr,size);//   -->2nd method
    cout<<secndlargest<<"\n";


    return 0;
}