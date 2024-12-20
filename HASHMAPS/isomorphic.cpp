#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool checkOneToManyMapping(string s1,string s2){
    unordered_map <char,char> m;
    for(int i = 0;i < s1.length();i++){
        if(m.find(s1[i]) != m.end()){
            if(m[s1[i] != s2[i]]){
                return false;
            }
            
        }
        else{
            return m[s1[i]] == s2[i];
        }

    }
    return true;
}
bool checkIsomorphic(string s1,string s2){
    if(s1.length() != s2.length()) return false;
    bool s1s2 = checkOneToManyMapping(s1,s2);
    bool s2s1 = checkOneToManyMapping(s2,s1);
    return (s1s2 && s2s1);

}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<(checkIsomorphic(s1,s2)? "Isomorphic" : "not Isomorphic");



    return 0;
}