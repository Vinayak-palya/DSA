#include<iostream>
#include<vector>
using namespace std;
bool canplacestd(vector<int> &pos,int s,int mid){
    int stu_req = 1;
    int last_place = pos[0];
    for(int i = 1;i < pos.size();i++){
        if(pos[i] - last_place >= mid){
            stu_req++;
            last_place = pos[i];
            if(stu_req == s) return true;
        }
    }
    return false;
}
int race(vector<int> &pos,int s){
    /*
    Space: O(1);
    Time: O(nlog(xn - x1));
    */
   
    int n = pos.size();
    int lo = 1;
    int ans = -1;
    int hi = pos[n - 1] - pos[0];
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(canplacestd(pos,s,mid)){
            ans = mid;
            lo = mid + 1;

        }else{
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
    int s;
    cin>>s;
    cout<<race(v,s)<<" ";

    return 0;
}