#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> targetSumPair(vector<int> v,int target){
    unordered_map<int , int> m;
    vector<int> res(2,-1);
    for(int i = 0;i < v.size();i++){
        if(m.find(target - v[i]) != m.end()){
            res[0] = m[target - v[i]];
            res[1] = i;
            return res;
            
        }
        else{
            m[v[i]] = i;
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];

    }
    int targetSum;
    cin>>targetSum;
    vector<int> ans  = targetSumPair(v,targetSum);
    
    cout<<ans[0]<<" , "<<ans[1]<<endl;


    return 0;
}