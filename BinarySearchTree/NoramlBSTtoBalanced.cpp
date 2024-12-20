#include<iostream>
#include<vector>
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
int solve(Node* root , int& i , int k){
    // base case
    if(root == NULL){
       return -1;
    }
    // L
    int left = solve(root->left , i , k);

    if(left != -1){
        return left;
    }
    // N
    i++;
    if(i == k){
        return root->data;
    }
    // R
    return solve(root->right , i , k);

}
int kthSmallest(Node* root , int k){
    int i = 0;
    int ans = solve(root , i , k);
    return ans;
}
pair<int , int> predecessorSuccesor(Node* root , int key){
    // find key
    Node* temp = root;
    int succ , pred;
    pred = succ = -1;
    while(temp->data != key && temp != NULL){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
            
        }
        else {
            pred = temp->data;
            temp = temp->right;
            

        }

        
    }
    if(temp == NULL){
        return make_pair(pred , succ);
    }
    // pred
    Node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    // succ
    Node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int , int> ans = make_pair(pred , succ);
    return ans;
}
Node* LCA_BST(Node* root , int n1 , int n2){
    // if(root == NULL) 
    //    return NULL;
    // if(root->data < n1 && root->data <n2){
    //     return LCA_BST(root->right , n1 , n2);
    // }
    // if(root->data > n1 && root->data > n2){
    //     return LCA_BST(root->left , n1 , n2);

    // }
    // return root; // recursive solution

    while(root != NULL){
        if(root->data < n1 && root->data < n2){
            root = root->right;
        }
        else if(root->data > n1 && root->data > n2){
            root = root->left;
        }
        else{
            return root;
        }

    }
    return root;
}
void Inorder(Node* root  , vector<int>& in){
    if(root == NULL){
        return ;

    }
    Inorder(root->left , in);
    in.push_back(root->data);
    Inorder(root->right , in);
}
bool twoSuminBST(Node* root , int a , int b){
    vector<int> inorderVal;
    // stroed inorder -> sorted value
    int target = a + b;
    Inorder(root , inorderVal);
    int i = 0;
    int j = inorderVal.size() - 1;
    while(i < j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }

    }
    return false;

}
Node* FlattenBST(Node* root){
    vector<int> inorderVal;
    Inorder(root , inorderVal);
    int n = inorderVal.size();
    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;
    for(int  i = 1;i < n;i++){
        Node* temp = new Node(inorderVal[i]);
        curr->right = temp;
        curr->left = NULL;
        curr = temp;
    }
    // 3rd step
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
Node* inordertoBST(int s , int e , vector<int> inorderVal){
    if(s > e){
        return NULL;
    }
    int mid = (s + e)/2;
    Node* root = new Node(inorderVal[mid]);
    root->left = inordertoBST(s , mid - 1 , inorderVal);
    root->right = inordertoBST(mid + 1 , e , inorderVal);
    return root;
}
Node* NormaltoBalancedBST(Node* root){
    vector<int> inorderVal;
    Inorder(root , inorderVal);
    int n = inorderVal.size() - 1;
    return inordertoBST(0 , n , inorderVal);


}


int main(){
    return 0;
}