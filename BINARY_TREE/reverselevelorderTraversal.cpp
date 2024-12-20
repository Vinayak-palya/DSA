#include<iostream>
#include<stack>
#include<queue>

using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        this->left = NULL;
        this->right = NULL;
        this->data = val;

    }
};
void buildTree(node* &root){
    int data;
    cout<<"Enter the data for the node : "<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1) {
        root = NULL;
        return ;

    }
    
    cout<<"Enter the data for entering in the left of the root"<<data<<endl;
    buildTree(root->left);

    cout<<"Enter the data for entering in the right of the root"<<data<<endl;
    buildTree(root->right);

}


void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);

            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }

    }
}
void reverseOrderTraversal(node* root){
    if(root == NULL) return ;
    stack<node*> s;
    queue<node*> q;
    q.push(root);


    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);
        
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    
}
int main(){
    node* root = NULL;
    buildTree(root);
    reverseOrderTraversal(root);


    return 0;
}