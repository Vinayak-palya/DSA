#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int LongestTargetSubArray(vector<int> &v){
    unordered_map<int , int> m;
    int prefixSum = 0;
    int maxLength = 0;
    for(int i = 0;i < v.size() ;i++){
        prefixSum+=v[i];
        if(prefixSum == 0) maxLength++;
        if(m.find(prefixSum) != m.end()){
            maxLength = max(maxLength,i - m[prefixSum]);
            

        }
        else{
            m[prefixSum] = i;

        }

    }
    return maxLength;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }

    cout<<LongestTargetSubArray(v)<<endl;;



    return 0;
}