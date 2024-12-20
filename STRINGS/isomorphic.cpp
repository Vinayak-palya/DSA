#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool IsIsomorphic(string s1,string s2){
    vector<int> v1(128,-1);
    vector<int> v2(128,-1);
    if(s1.size() != s2.size()){
        return false;
    }
    for(int i = 0;i < s1.size();i++){
        if(v1[s1[i]] != v2[s2[i]]) return false;//checking if value of index i match in both vectors
        v1[s1[i]] = v2[s2[i]] = i;//storing string position in vectorsfor character  at idx i
    }
    return true;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(IsIsomorphic(s1,s2)){
        cout<<"given strings are isomrphic"<<"\n";
    }
    else cout<<"they are not isomorphic";
    return 0;
}