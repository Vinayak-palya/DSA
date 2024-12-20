#include<iostream>
#include<vector>
using namespace std;
int sqrtbinarysearch(vector<int> &v){
    int lo = 0;
    int n = v.size();
    int hi = v.size() - 1;
    int ans;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mid * mid <= n){
            ans = mid;
            lo = mid + 1;

        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 1;i < n;i++){
        v[i] = i+1;
    }
    int sqrt = sqrtbinarysearch(v);
    cout<<"square root of "<< n << " is :"<< sqrt<< " ";

    return 0;
}