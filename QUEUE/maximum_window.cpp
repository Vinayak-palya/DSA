#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int>  max_window(vector<int> &arr,int k){
    deque<int> dq;
    vector<int> res;
    for(int i = 0;i < k;i++){
        while(not dq.empty() and dq.back() < arr[i]){
            dq.pop_back();

        }
        dq.push_back(i);

    }
    res.push_back(arr[dq.front()]);
    for(int i = 0;i < arr.size();i++){
        int curr = arr[i];
        if(dq.front() == i - k) dq.pop_front();
        while(not dq.empty() and dq.back() < arr[i]){
            dq.pop_back();

        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);

    }
    return res;
}
int main(){

    return 0;
}