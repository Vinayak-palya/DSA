#include<iostream>
using namespace std;
void search(int arr[],int n,int target,int res[]){
    int lo = 0;
    int hi = n-1;
    res[0] = -1;
    res[1] = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] < target){
            lo = mid + 1;
            
        }
        else {
            hi = mid -1;
            res[0] = mid;
        }
        
    }
    if(arr[res[0]] != target){
        res[0] = -1;
        res[1] = -1;
    return ;
    }
     lo = 0;
     hi = n-1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(arr[mid] > target){
            hi = mid -1;
            
        }
        
        else{
            lo = mid + 1;
            res[1] = mid;
        }
    }

    return ;
}
int main(){
    int n;
    cin>> n;
    int arr[n];

    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int res[2];
    search(arr,n,target,res);
    for(int i = 0;i < 2;i++){
        cout<<res[i]<<" ";
    }cout<<endl;
    return 0;
}
