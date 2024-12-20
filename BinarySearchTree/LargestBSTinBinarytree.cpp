#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }

};
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;

};
info solve(Node* root , int &ans){
    // base case
    if(root == NULL){
        return {INT_MIN ,INT_MAX , true , 0};
    }
    
    info left = solve(root->left , ans);
    info right = solve(root->right , ans);
    
    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data , right.maxi);
    currNode.mini = min(root->data , left.mini);

    if(left.isBST and right.isBST and (root->data > left.maxi and root->data < right.mini)){
        currNode.isBST = true;

    }
    else{
        currNode.isBST = false;
    }
    // update ans
    if(currNode.isBST){
        ans = max(ans , currNode.size);
    }
    return currNode;
}
int LargestBST(Node* root){
    int maxSize = 0;
    info temp = solve(root , maxSize);
    return maxSize;
}
int main(){

    return 0;
}