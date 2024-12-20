#include<iostream>
using namespace std;
int main(){
    int arr[]={3,4,6,7,1};
    int targetsum=5;
    int size =5;
    int pairs=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==targetsum){
                pairs++;
            }
        }
    }
    cout<<pairs<<endl;
    return 0;
}