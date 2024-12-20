#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int> &input,int target){
    //define searchspace
    int lo = 0;//start search space
    int hi = input.size();//end search space
    while(lo <= hi){
        //calc mid point for the search space
        int mid = lo + (hi - lo)/2;//int mid = (lo + hi)/2;//modified mid to tackle overflow
        if(input[mid] == target){
            
            return mid;
        }
        else if(target < input[mid]){
            //discard the right part of the mid
            hi = mid - 1;
        }
        else{
            //discard the left of mid
            lo = mid + 1;
        }
    }
    return -1;

}
int main(){
    int n,target;
    cin>> n;

    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin>>v[i];
    }
    cin>>target;
    int tar_idx = binarysearch(v,target);
    if(tar_idx != -1){
        cout<<tar_idx<<" ";
    }
    else{
        cout<<"target not present"<<" ";
    }
    return 0;
}