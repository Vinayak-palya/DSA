#include<iostream>
#include<map>
#include<vector>
using namespace std;
/* 
time complexity = O(N);
space complexity = O(N);
*/
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0;i < n;i++){
        cin>>input[i];
    }
    map<int , int> freq;
    for(int i = 0;i < n;i++){
        freq[input[i]]++;
    }
    //finding the sum of the repetitive element  
    int sum = 0;

    /*
    [1,2] , [7,1]
    m[1]++
    m[1]++
    m[7]++
    */
    for(auto ele: freq){
        if(ele.second > 1){
        sum += ele.first;
        }
    }
    cout<< sum << " ";

    return 0;
}