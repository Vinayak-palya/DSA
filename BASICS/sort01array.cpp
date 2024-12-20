#include<iostream>
#include<vector>
using namespace std;
void sortZeroandOnes(vector<int> &v){
    int zeros_count=0;
    for(int ele=0;ele<v.size();ele++){
        if(v[ele]==0){
            zeros_count++;
        }
    }
    for(int i=0;i<v.size();i++){
        if(i<zeros_count){
            v[i]=0;

        }
        else {
            v[i]=1;
            }
    }
    return;
}
// void sortZeroandOnes(vector<int> &v) {
//     int zeros_count = 0;
//     for(int ele = 0; ele < v.size(); ele++) {
//         if(v[ele] == 0) {
//             zeros_count++;
//         }
//     }
//     for(int i = 0; i < v.size(); i++) {
//         if(i < zeros_count) {
//             v[i] = 0;
//         } else {
//             v[i] = 1;
//         }
//     }
// }

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele;cin>>ele;
        
        v.push_back(ele);
    }
    // vector<int> v;
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    sortZeroandOnes(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
