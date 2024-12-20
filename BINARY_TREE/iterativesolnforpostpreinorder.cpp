#include<iostream>
#include<stack>
#include<vector>
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
Node* buildtree(Node * root){
    cout<<"enter the data for the node: "<<endl;
    int data;
    cin>>data;
    root  = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left of "<< data <<"\n";
    root->left = buildtree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;
}
void InorderTraversal(Node* root){
    Node* temp = root;
    stack<Node *> s1;
    Node* current;
    current = root;
    s1.push(root);
    while(!s1.empty() || current != NULL){
        while(current != NULL){
            s1.push(current);
            current = current->left;
        }

        current = s1.top();
        s1.pop();
        cout<<current->data<<" ";
        current  = current->right;

    
    }
    cout<<endl;
}

void PreorderTraversal(Node * root){
    Node* current = root;
    stack<Node* > s;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);

    }
    cout<<endl;

}
void postorder(Node* root){
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);


    }
    while(!s2.empty()){
        Node* curr = s2.top();
        s2.pop();

        cout<<curr<<" ";

    }
    cout<<endl;
}

int main(){
    Node* root = NULL;

    // creating a Tree

    root = buildtree(root);
    
    // level order traversal


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"PreorderTraversal is: ";
    PreorderTraversal(root);
    return 0;
    
}