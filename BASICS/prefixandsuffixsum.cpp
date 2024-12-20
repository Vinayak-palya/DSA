#include<iostream>
#include<vector>
using namespace std;

// bool presuffixsum(vector<int> &v){

//     int prefixsum=0;
//     int suffixsum=0;
//     for(int k=0;k<v.size()-1;k++){
//         int prefixsum=0;
//         int suffixsum=0;
//         for(int i=0;i<=k;i++){
//             prefixsum+=v[i];
//         }
//         for(int i=k+1;i<v.size();i++){
//             suffixsum+=v[i];
//         }
//         if(prefixsum==suffixsum){
//             return true;
//         }
        
//     }
//     return false;
// }
bool presuffixsum(vector<int> &v){
    int total_sum=0;
    for(int i=0;i<v.size();i++){
        total_sum+=v[i];

    }
    int prefix_sum=0;
    for(int i=0;i<v.size();i++){
        prefix_sum+=v[i];
        int suffix_sum=total_sum-prefix_sum;
        if(suffix_sum==prefix_sum){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];

    }
    
    cout<<presuffixsum(v)<<"\n";
    return 0;
}