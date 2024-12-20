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
    pair<bool,int> IsBalancedopt(node*);
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


bool node :: IsBalanced(node* root){ // time complexity --> O(N^2);


    if(root == NULL) return true;
    bool left = IsBalanced(root->left);
    bool right = IsBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if(left && right && diff){
        return true;
    }

    return false;

}


pair <bool,int> node :: IsBalancedopt(node* root){ // time compl --> O(N);
    if(root == NULL){
        pair<bool , int> p = make_pair(true,0);
        return p;

    }
    pair<bool ,int> left = IsBalancedopt(root->left);
    pair<bool , int> right  = IsBalancedopt(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <=1;
    pair<bool , int> ans;
    ans.second = max(left.second , right.second) + 1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return  ans;
}


bool IsIdentical(node* r1,node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
        return false;
    }
    bool left = IsIdentical(r1->left , r2->left);
    bool right = IsIdentical(r1->right , r2->right);
    bool value = r1->data == r2->data;
    if(left && right && value){
        return true;

    }
    else{
        return false; // time compl--> O(N);
    }
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