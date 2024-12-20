#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data = value;
        left = NULL;
        right = NULL;
    }

};
Node* createBST(Node* root , int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    
    if(d > root->data){
        // right part main insert karna hai
        root->right = createBST(root->right , d);

    }
    else{
        // left part main insert karna hai
        root->left = createBST(root->left , d);
    }

    return root;


}

void input(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = createBST( root , data);
        cin >> data;
    }

}
bool isBST(Node* root , int min , int max){
    // base case
    if(root == NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left , min , root->data);
        bool right = isBST(root->right , root->data , max);
        if(left && right){
            return true;
        }
    }
    return false;

}
bool validateBST(Node* root){
    return isBST(root , INT_MIN , INT_MAX);
}
int main(){
    return 0;
}