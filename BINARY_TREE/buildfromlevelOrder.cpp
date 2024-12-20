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
void BuildformLevelOrder(node* &root){
    queue<node*> q;
    cout<<"enter the data for the root" << endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();


        cout<< "Enter left node for the data "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);

        }
        cout<< "Enter right node for the data "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);


        }
    }
}
int main(){
    node* root = NULL;

    // creating a Tree

    BuildformLevelOrder(root);
    
    // level order traversal
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    return 0;
}