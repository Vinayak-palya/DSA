#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* solve(vector<int> preorder  , int maxi , int & i){
    if(i >= preorder.size()){
        return NULL;
    }
    // if(preorder[i] < || preorder[i] > maxi){
    //     return NULL;
    // }
    if(preorder[i] > maxi) return NULL;
    
    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder , root->data , i);
    root->right = solve(preorder , maxi , i);
    
    
    return root;
}
Node* solve(vector<int> preorder , int mini , int maxi , int & i){
    if(i >= preorder.size()){
        return NULL;
    }
    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL;
    }
    Node* root = new Node(preorder[i++]);
    if(preorder[i] > root->data)
    root->right = solve(preorder , root->data  , maxi , i);
    else
    root->left = solve(preorder , mini , root->data , i);
    
    return root;
    
    
}
Node* preorderToBST(Node* root , vector<int> preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder , mini , maxi , i);
}
int main(){

    return 0;
}