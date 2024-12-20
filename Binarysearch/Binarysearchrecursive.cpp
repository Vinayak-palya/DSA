#include<iostream>
#include<vector>
using namespace std;
int binarysearchrecursive(vector<int> &input,int target,int lo,int hi){
    if(lo > hi) return -1;
    int mid = lo + (hi - lo)/2;//int mid = (lo + hi)/2;
    if(input[mid] < target){
        return binarysearchrecursive(input,target,mid + 1,hi);
    }
    else if(input[mid] > target){
        return binarysearchrecursive(input,target,lo,mid-1);
    }
    else return mid;
   
}

int main(){
    int n,target;
    cin>> n;

    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin>>v[i];
    }
    cin>>target;
    int tar_idx = binarysearchrecursive(v,target,0,n-1);
    if(tar_idx != -1){
        cout<<tar_idx<<" ";
    }
    else{
        cout<<"target not present"<<" ";
    }
    return 0;
}