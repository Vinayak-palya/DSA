#include<iostream>
#include<queue>
using namespace std;

/*
time complexity = O(N)
space complexity = O(height);
*/
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
void InorderTraversal(node* root){
    // base case
    if(root == NULL){
        return ;
    }
    InorderTraversal(root->left);
    cout<< root->data<<" ";
    InorderTraversal(root->right);
    return ;
}

int height(node* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right) + 1;
    return ans;
}
// optimized solution
pair<int,int> diameteropt(node*root){// --> O(N)
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameteropt(root->left);
    pair<int,int> right = diameteropt(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int,int> ans ;
    ans.first =  max(op1 , max(op2,op3));
    ans.second = max(left.second , right.second) +1;
    
    return ans;


}

int Diameter(node* root){ // time complexity =  O(N^2);

    return diameteropt(root).first;



}


int main(){
    node* root = NULL;

    // creating a Tree

    root = buildtree(root);
    
    // level order traversal
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<Diameter(root)<<" ";

    
    return 0;
}