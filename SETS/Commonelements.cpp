#include<iostream>
#include<set>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    
    cout<<"Enter the elements of v1: "<<endl;
    for(int i = 0;i < n;i++){
        cin>>v1[i];
    }
    cout<<"Enter the elemnts of v2: "<<endl;
    for(int i = 0 ;i < m;i++){
        cin>>v2[i];

    }
    int ans_sum = 0;
    set<int> s1;
    for(int i = 0;i < n;i++){
        s1.insert(v1[i]);
    }
    for(int i = 0;i < m;i++){
        if(s1.find(v2[i]) != s1.end()){
            ans_sum += v2[i];
        }
    }
    cout<<"Ans = "<<ans_sum<<endl;
    
    return 0;
}