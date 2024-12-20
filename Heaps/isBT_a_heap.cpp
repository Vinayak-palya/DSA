// #include<bit/stdc++.h>
#include<iostream>
#include<queue>
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
int countNode(Node* root){
if(root == NULL){
    return 0;
}
    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}
bool isCBT(Node* root , int i , int totalCount){ // time ciomplexity --> O(n);
// space complexity-->o(n);
    if(root == NULL){
        return true;
    }
    if(i >= totalCount){
        return false;
    }
    else{
        bool left = isCBT(root->left , 2*i + 1 , totalCount);
        bool right = isCBT(root->right , 2*i + 2 , totalCount);
        if(left && right) return true;
    }
    return false;
}
bool isMaxOrder(Node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    else if(root->right == NULL){
        return root->data > root->right->data;
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left && right && (root->data > root->right->data && root->data > root->left->data));
    }
    return false;

}

bool isHeap(Node* root){
    int index = 0;
    int totalCount = countNode(root);
    if(isCBT(root , index , totalCount) && isMaxOrder(root)){
        return  true;
    }
    else  return false;
}
int main(){

    return 0;
}