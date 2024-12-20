#include<iostream>
#include<queue>
using namespace std;

/*
time complexity = O(N)
space complexity = O(height);
*/
class node{
    private:
    int height(node* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right) + 1;
    return ans;
}

    public: 
    int data;
    node* left;
    node* right;
    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    bool IsBalanced(node*);
    
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



pair<bool , int> IsSumTree(node* root){
    //base case // time comp --> O(N)
    if(root == NULL){
        pair<bool , int> ans = make_pair(true,0);
        return ans;
    }
    //leaf node
    if(root -> left == NULL && root -> right == NULL){
        pair<bool ,int> p = make_pair(true , root->data);
        return p;
    }
    pair<bool , int> leftAns = IsSumTree(root->left);
    pair<bool , int> rightAns = IsSumTree(root->right);
    bool left = leftAns.first;
    bool right = rightAns.first;
    bool cond = leftAns.second + rightAns.second == root->data;
    pair<bool ,int>ans;
    if(left && right && cond){
        ans.first = true;
        ans.second = 2*root->data;

    }
    else{
        ans.first = false;
        ans.second = 2* root->data;

    }
    return ans;

}
bool IsSumTreeFast(node* root){
    return IsSumTree(root).first;
}



int main(){
    node* root = NULL;

    // creating a Tree

    root = buildtree(root);
    
    // level order traversal
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    cout<<IsBalanced(root)<<"endl ";


    
    return 0;
}