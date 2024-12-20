#include<iostream>
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
Node* createBST(Node* root , int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root->data < val){
        root->right = createBST(root->right , val);
    }
    else{
        root->left = createBST(root->left , val);
    }

    return root;

}
void InserttoBST(Node* &root){
    int data;
    cin>>data;
    root = new Node(data);
    while(data != -1){
        root = createBST(root , data);
        cin>>data;
    }
    return ;
}
int maxEle(Node* root){
    Node* temp = root;
    while(temp != NULL){
        temp = temp->right;

        

    }
    return temp->data;

}
int minEle(Node* root){
     Node* temp = root;
    while(temp->left != NULL){
        
        temp = temp->left;

    }
    return temp->data;

}
pair<int , int> predecessorSuccessor(Node* root , int val){
    Node* temp = root;
    int pred = 0;
    int succ = 0;
    
    while(temp->data != val && temp != NULL){
        if(temp->data < val && temp->right != NULL){
            succ = temp->data;
            temp = temp->right;
        }
        else if(temp->data > val && temp->left != NULL){
            pred = temp->data;
            temp = temp->left;
        }
    }
    if(temp == NULL){
        return make_pair(pred , succ);
    }
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return make_pair(pred , succ);



}
int main(){

    return 0;
}