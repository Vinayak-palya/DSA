#include<iostream>
#include<vector>
using namespace std;
bool canDistchoco(vector<int> &arr,int mid,int s){
    int stu_req = 1;
    int n = arr.size();
    int curr_sum = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] > mid){// this condition implies that we always have to search in the right
        // half of the search space because individual 
        //choclate box is having element greater than half;
            return false;
        }
        if(curr_sum + arr[i] > mid)
        {
            stu_req++;
            curr_sum = arr[i];
            
            if(stu_req > s) return false;
        }
        else
        {
            curr_sum += arr[i];
        }
    }
    return true;
}
int distchoclate(vector<int> &arr,int s){
    int n = arr.size();
    int lo = arr[0];
    int hi = 0;
    for(int i = 0;i < n;i++){
        hi += arr[i];
    }
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(canDistchoco(arr,mid,s)){
            ans = mid;
            hi = mid - 1;

        }else{
            lo = mid + 1;

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
    int s;
    cin>>s;
    cout<<distchoclate(v,s)<<" ";
    return 0;
}