#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i = 0;i < 26;i ++ ){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
//  Assumption that  all letters are in caps
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root , string word){
        //  base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }
        int index = word[0] - 'a';
        TrieNode * child ;
        //If present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // if absent
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child , word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root , word);
        return ;
    }
    bool searchUtil(TrieNode* root , string word){
        //  base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        // if present
        int index = word[0] - 'a';
        TrieNode* child ;
        // if absent
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // recursion
        else{
            return false;
        }
        return searchUtil(child , word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root , word);
    }
    bool prefixUtil(TrieNode* root , string prefixw){
        //  base case
        if(prefixw.length() == 0){
            return true;
        }
        // if present
        int index = prefixw[0] - 'a';
        TrieNode* child ;
        // if absent
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        // recursion
        else{
            return false;
        }
        return prefixUtil(child , prefixw.substr(1));
    }
    bool prefix(string prefixw){
        return prefixUtil(root , prefixw);
    }

    bool isEmpty(TrieNode* root){
        for(int i = 0;i < 26;i++){
            if(root->children[i] != NULL){
                return false;
            }

        }
        return true;
    }
    void removeUtil(TrieNode* root ,string word){
        int length = word.length();
        
        if(root->isTerminal && isEmpty(root))
        {

            delete(root);
            return ;
        }
        int index = word[0] - 'a';

        removeUtil(root->children[index], word.substr(1));
        if(isEmpty(root) and root->isTerminal){
            delete(root);
        }
        return ;

    }
    void remove(string word){

        removeUtil(root , word);
        return ;
    }
    void printSuggestion(TrieNode* curr , vector<string> &temp , string prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
        // we have not used return statement because there can be more valid words  even if it is terminal

    }
    for(char i = 'a';i <= 'z';i++){
        TrieNode* next = curr->children[i - 'a'];
        if(next != NULL){
            prefix.push_back(i);
            printSuggestion(next , temp , prefix);
            prefix.pop_back();
        }
    }
    return ;

}
    vector< vector<string> >getSuggestion(string queryStr){
        TrieNode* prev = root;
        vector<vector<string> > output;
        string prefix = "";
        for(int i = 0;i < queryStr.size();i++){
            char lastch = queryStr[i];
            prefix.push_back(lastch);
            TrieNode* curr = prev->children[lastch - 'a'];

            // check 
            if(curr == NULL){
                break;
            }
            vector<string> temp;
            printSuggestion(curr , temp , prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
    
};

     vector<vector<string> >phoneDirectory(vector<string> & contactList , string & queryStr){
        Trie* t = new Trie();
        for(int i = 0;i < contactList.size();i++){
            t->insertWord(contactList[i]);

        }
        
        return t->getSuggestion(queryStr);
    }


int main(){
    
    vector<string> contactList;
    contactList.push_back("coding");
    contactList.push_back("codehelp");
    contactList.push_back("cod");
    string query = "co";
    
    vector<vector<string> > result = phoneDirectory(contactList, query);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}