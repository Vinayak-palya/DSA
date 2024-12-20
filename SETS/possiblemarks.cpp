#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int n,p,q;
    cin>>n>>p>>q;
    unordered_set<int> s;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= n - i;j++){
            int correct = i;
            int wrong = j;
            int unattempted = n - i - j;
            int score = correct*p + wrong*q;
            s.insert(score);

        }
    }
    // for(int value: s){
    //     cout<<value<<" ";
    // }
    cout<<s.size()<<"\n";
    return 0;

}