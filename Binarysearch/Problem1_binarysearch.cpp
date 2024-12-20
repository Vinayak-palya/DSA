#include<iostream>
#include<vector>
using namespace std;

int firstoccurence(vector<int> &v,int target){
    int ans = -1;
    int lo = 0;
    int hi = v.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(v[mid] == target){
            ans = mid;
            hi = mid -1;
        }
        else if(v[mid] < target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    int target;
    cin>>target;
    int first_tar_idx = firstoccurence(v,target);
    if(first_tar_idx == -1){
        cout<<"target not present"<<" ";

    }
    else{
        cout<<"min target index is -->"<<first_tar_idx<<" ";
    } cout<<endl;
    return 0;
}