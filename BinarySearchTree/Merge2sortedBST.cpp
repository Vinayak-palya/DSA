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
vector<int> mergeArr(vector<int >bst1 , vector<int> bst2){
    int i = 0 , j = 0 , k = 0;
    vector<int> ans(bst1.size() + bst2.size() - 1);
    while(i < bst1.size() && j < bst2.size()){
        if(bst1[i] < bst2[j]){
            ans[k++] = bst1[i++];
        }
        else{
            ans[k++] = bst2[j++];
        }
    }
    while(i < bst1.size()){
        ans[k++] = bst1[i++];
    }

    while(j < bst2.size()){
        ans[k++] = bst2[j++];
    }
    return ans;
}
void inorder(Node* root  , vector<int> &v){
    if(root == NULL) return ;
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
    return ; 
}

Node* inordertoBST(vector< int > res , int s ,int e){
    if(s > e){
        return NULL;
    }
    int mid = (s + e)/2;
    Node* root = new Node(mid);
    root->left = inordertoBST(res , s ,mid - 1);
    root->right = inordertoBST(res , mid+1 , e);
    return root;
}
 Node* merge(Node* root1 , Node* root2){
    vector<int> bst1 , bst2;
    inorder(root1 , bst1);
    inorder(root2 , bst2);
    vector<int> result = mergeArr(bst1 , bst2);
    Node* res = inordertoBST(result , 0 ,result.size() - 1);
    return res;

 }

void convertIntoSortedLL(Node* root , Node* & head){
    // base case
    if(root == NULL){
        return ;
    }
    convertIntoSortedLL(root->right , head);
    root->right = head;
    if(head != NULL)
    head->left = root;
    head = root;
    convertIntoSortedLL(root->left , head);
}
Node* mergeLL(Node* head1 , Node* head2){
    Node* head = NULL;
    Node* tail = NULL;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }

        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head1 = head2->right;
    }
    return head;
    
}
int countNodes(Node* head){
    int count = 0 ;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->right;
        count++;
    }
    return count;
}
Node* BSTfromLL(Node* & head , int n){
// base case
    if(n <= 0 && head == NULL) return NULL;
    Node* left = BSTfromLL(head , n / 2);
    Node* root = head;
    root->left = left;
    
    head = head->right;
    root->right= BSTfromLL(head , n - n/2 -1);
    return root;




}





int main(){
    Node* root = NULL;

    cout<<"Enter the data to create  a BST"<<endl;
    input(root);
    cout << "Printing the BST"<< "\n";
    levelOrderTraversal(root);

    




    return 0;
}