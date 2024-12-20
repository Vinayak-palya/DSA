#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
bool checkAnagram(string s1,string s2){
    if(s1.length() != s2.length()) return false;
    unordered_map <char,int>  m;

    for(auto c :s1){
        m[c]++;// storing characters and ther frequency in map
    }
    for(auto c : s2){
        if(m.find(c) == m.end()) return false;
        m[c]--;
    }
    for(auto ele : m){
        if(ele.second != 0) return false;

    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<< (checkAnagram(s1,s2) ? "Anagram" : "Not Anagram")<<endl;
     

    return 0;
}