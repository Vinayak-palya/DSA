#include<iostream>
#include<vector>
using namespace std;
int findMinIn_rotated_sorted(vector<int> &input){
    if(input.size() == 1) return 0;
    int lo = 0,hi = input.size()-1;
    if(input[lo] < input[hi]){
        return lo;
    }
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if((input[mid] > input[mid+1])  && (mid < input.size() - 1)) return mid + 1;
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
    int min_idx = findMinIn_rotated_sorted(v);
    cout<<min_idx;
    
    return 0;
}