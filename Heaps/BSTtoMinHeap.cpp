#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
class heap{
    public:
    int arr[100];
    int size ;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void Insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[index] , arr[parent]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i = 1;i <= size;i++){
            cout << arr[i] << " ";

        }cout << endl;
    }
    void deleteFromHeap(){
        if(size == 0){
            cout << "Nothing to delete" << endl;
            return ;
        }
        // step 1 inserting the element of the last node replacing the root
        arr[1] = arr[size];
        size --;

        // take root node to its correct postition
        int i = 1;
        while(i < size){
            int left_index = 2*i;
            int right_index = 2*i + 1;
            if(left_index < size and arr[left_index] > arr[i]){
                swap(arr[i] , arr[left_index]);
                i = left_index;
            }
            else if(right_index < size and arr[right_index] > arr[i]){
                swap(arr[i] , arr[right_index]);
                i = right_index;
            }
            else{
                return ;
            }
        }
    }
};
long long minCost(long long arr[] , long long n){
    priority_queue < long long , vector< long long > , greater<long long> > pq;
    long long  cost = 0;
    for(int i = 0; i < n;i++){
        pq.push(arr[i]);
    }
    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        long long sum = a + b;
        cost += sum;
        pq.push(sum);

    }
    return cost;
}
void inorderstore(Node* root , vector<int> &inorder){
    // base case
    if(root == NULL){
        return ;
    }
    inorderstore(root->left , inorder);
    inorder.push_back(root->data);
    inorderstore(root->right , inorder);

    return ;

}
void fillPreorder(Node* root , vector<int> inorder , int& index){
    if(root == NULL){
        return ;
    }
    root->data = inorder[index++];
    fillPreorder(root->left , inorder , index);
    fillPreorder(root->right , inorder , index);
    return ;

}
int main(){

    return 0;
}