#include<iostream>
#include<vector>
using namespace std;
int binarysearchsortedrotated(vector<int> &v,int target){
    int lo = 0; 
    int hi = v.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(v[mid] == target) return mid;
        if(v[lo] <= v[mid]){
            if(target  >= v[lo] && target < v[mid]){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        else{
            if(target > v[mid] && target <= v[hi]){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
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
    int tar_idx = binarysearchsortedrotated(v,target);
    if(tar_idx != -1){
        cout<<tar_idx<<" ";
    }
    else{
        cout<<"target not present"<<" ";
    }
    return 0;
}