#include<iostream>
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
        int index = word[0] - 'A';
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
        int index = word[0] - 'A';
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
        int index = prefixw[0] - 'A';
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
        int index = word[0] - 'A';

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
};
int main(){
    Trie * t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("TIME"); 
    t->insertWord("TIMING"); 
    t->insertWord("ABCDEFGHIJK");
    t->remove("ABCDEFGHIJK");
    t->insertWord("THEIR");
    t->insertWord("THERE");
    t->remove("THERE");

    cout << "present or not : " << t->searchWord("THERE") << endl;
    return 0;
}