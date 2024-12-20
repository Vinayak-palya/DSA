#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool IsAnagram(string s1,string s2){
    //create a frequency array;
    vector<int> freq(26,0);
    if(s1.length() != s2.length()) return false;
    for(int i = 0;i < s1.length();i++){
        int index = s1[i] - 'a';
        freq[index]++;
        freq[s2[i] - 'a']--;
    }
    for(int i = 0;i < 26;i++){
        if(freq[i] != 0) return false;
        
    }
    return true;
    
}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    if(IsAnagram(s1,s2)) cout<<"STRINGS are anagram";
    else{
        cout<<"strings are not anagram";
    }

    return 0;
}