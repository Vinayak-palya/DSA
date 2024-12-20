#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    char data;
    int childCount;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i = 0;i < 26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root , string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
        }
        // assuming all letters as caps
        int index = word[0] - 'A';
        TrieNode* child;
        //if present;
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
            
        }
        insertUtil(root , word.substr(1));
        
    }
    void insertWord(string word){
        insertUtil(root , word);
        return;
    }
    void lcp(string s , string & ans){
        for(int i = 0;i < s.length();i++){
            char ch = s[i];
            
            if(root->childCount == 1){
                ans+=ch;
                int index = s[i] - 'a';
                root = root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal) break;
        }
        return;
    }
    
};
string longestCommonPrefix(vector<string> &arr , int n){
    Trie* t = new Trie();
    for(int i = 0;i < n;i++){
        t->insertWord(arr[i]);
    }
    string ans = "";
    string s = arr[0];
    t->lcp(s , ans);
    return ans;

}

// 1st solution
// string longestCommonPrefix(vector<string> arr , int n){
//     string ans = "";
//     for(int i = 0;i < arr[0].length();i++){
//         char ch = arr[0][i];
//         bool match = true;
//         // for comparing string with rest of the condition
//         for(int j = 1;j < n;j++){
//             //not match condition
//             if(arr[j].size() < i || ch != arr[j][i]){
//                 match = false;
//                 break;
//             }

//         }
//         if(match == false){
//             break;
//         }
//         else{
//             // ans+=ch;
//             ans.push_back(ch);
//         }




//     }
//     return ans;
// }
int main(){
    
    return 0;
}