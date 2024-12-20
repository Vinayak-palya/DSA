#include<iostream>
#include<vector>
using namespace std;
void runningsum(vector<int> &v){
    int cumulativesum=0;

    for(int i=1;i<v.size();i++){
        v[i]+=v[i-1];
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];

    }
    runningsum(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";

    }
    cout<<"\n";
    return 0;
}