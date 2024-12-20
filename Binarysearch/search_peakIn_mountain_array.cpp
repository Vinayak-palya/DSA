#include<iostream>
#include<vector>
using namespace std;
int mountainpeak(vector<int> &input){
    int lo = 0;
    int hi = input.size() - 1;
    int ans = -1;
while(lo <= hi){
    int mid = lo + (hi - lo)/2;
    if(input[mid - 1] < input[mid]){
        lo = mid + 1;
        // ans = mid;  modifcation
        ans = max(mid,ans);
    }
    else{
        hi = mid-1;
    }

}
return ans ;

}
int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(4);
    v.push_back(1);
    v.push_back(0);
    cout<<mountainpeak(v);
    return 0;
}