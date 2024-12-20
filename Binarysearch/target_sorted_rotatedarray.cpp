#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &input,int lo,int hi,int target){
    //define searchspace
    
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
int findminInsortedrotated(vector<int> &input){
    if(input.size() == 1) return 0;
    int lo = 0,hi = input.size()-1;
    if(input[lo] < input[hi]){
        return lo;
    }
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(input[mid+1] < input[mid]) return mid + 1;
        if(input[mid] < input[mid-1]) return mid;
        if(input[mid] > input[lo]){
            lo = mid + 1;

        }
        else{
            hi = mid - 1;

        }
        
    }
    return -1;


}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    int target ;
    cin>>target;
    int min_idx = findminInsortedrotated(v);
    int tar_idx_1 = binarysearch(v,min_idx,n-1,target);
    int tar_idx_2 = binarysearch(v,0,min_idx-1,target);
    if(tar_idx_1 == -1){
        if(tar_idx_2 == -1){
            cout<<"target not present in an array"<<" ";

        }
        else{
            cout<<tar_idx_2<<" ";
        }

    }
    else{
        cout<<tar_idx_1<<" ";
    }
    return 0;
}