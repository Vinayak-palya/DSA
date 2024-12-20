#include<iostream>
#include<vector>
using namespace std;
bool searchmatrix(vector<vector<int> > &v,int target){
    int n = v.size();
    int m = v[0].size();
    int lo = 0;
    int hi = n*m -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        int x = mid / m;// x = mid/m and y = mid % m
        int y = mid%m;
        if(v[x][y] == target){
            return true;
        }
        else if(v[x][y] < target){
            lo = mid + 1;

        }
        else hi = mid - 1;

    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    int target;
    cin>>target;

    vector<vector<int> >   v(n,vector<int> (m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>v[i][j];
        }
    }
    cout<<searchmatrix(v,target)<<" ";

    return 0;
}