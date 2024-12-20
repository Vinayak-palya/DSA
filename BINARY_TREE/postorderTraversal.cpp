#include<iostream>
#include<queue>
using namespace std;
class node{
    public: 
    int data;
    node* left;
    node* right;
    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
node* buildtree(node * root){
    cout<<"enter the data for the node: "<<endl;
    int data;
    cin>>data;
    root  = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<< data <<"\n";
    root->left = buildtree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        node* temp = q.front();
        
        q.pop();
        if(temp == NULL){// purana level pura traverse ho chuka hai
            cout<< endl;
            if(!q.empty()){// queue still has some child nodes
            q.push(NULL);
            }
        }
        // q.push(NULL) act as a separator 
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);

            if(temp->right) q.push(temp->right);
        }

        
        
    }

}
void postorderTraversal(node* root){
    // base case
    if(root == NULL){
        return ;
    }

    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<< root->data<<" ";
}



int main(){
    node* root = NULL;

    // creating a Tree

    root = buildtree(root);
    
    // level order traversal
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"Inordertraversal is: ";
    postorderTraversal(root);

    return 0;
}