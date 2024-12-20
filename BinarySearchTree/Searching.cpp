#include<iostream>
// #include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
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
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            // purana levelvpuratravers karna hai
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<< " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        
    }
}
void InorderTraversal(Node* root){
    // base case
    if(root == NULL){
        return ;
    }
    InorderTraversal(root->left);
    cout<< root->data<<" ";
    InorderTraversal(root->right);
    return ;
}
void postorderTraversal(Node* root){
    // base case
    if(root == NULL){
        return ;
    }

    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<< root->data<<" ";
}
void preorderTraversal(Node* root){
    // base case
    if(root == NULL){
        return ;
    }

    cout<< root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


bool search(Node* root , int target){
    // base case
    if(root == NULL){
        return false;


    }
    if(root->data == target){
        return true;
    }
    
    if(root->data < target){
       return search(root->right , target);
    }
    else{
        return search(root->left , target);
    }

}

bool searchIterative(Node* root , int target){
    Node* temp = root;
    while(root){
        if(root->data == target){
            return true;
        }
        if(root->data < target){
            root = root->right;
        }
        else{
            root = root->left;
        }
        
    }
    return false;

}
Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    Node* temp = root;
    while(temp != NULL){
        temp = temp->right;
    }
    return temp;
}
Node* deleteFromBST(Node* root , int value){
    // Base case
    if(root == NULL){
        return root;
    }

    if(root->data == value){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        else if(root->left != NULL && root->right ==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } 
        // 2 child
        else{
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right , temp->data);
            return root;
        }

    }
    else if(root->data > value){
        root->left = deleteFromBST(root->left , value);
        return root;
        
        
    }
    else{
            root->right = deleteFromBST(root->right , value);
        }
        return root;
}



int main(){
    Node* root = NULL;

    cout<<"Enter the data to create  a BST"<<endl;
    input(root);
    cout << "Printing the BST"<< "\n";
    levelOrderTraversal(root);

    cout << "Inorder TRAVERSAL" << endl;
    InorderTraversal(root);

    cout << "preorder TRAVERSAL" << endl;
    preorderTraversal(root);

    cout << "postorder TRAVERSAL" << endl;
    postorderTraversal(root);





    return 0;
}