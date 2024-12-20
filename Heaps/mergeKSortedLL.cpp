#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
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
class compare{
    public:
    bool operator()(Node* a , Node* b){
        return a->data >b->data;
    }
    
};
Node* mergeKSortedklist(vector<Node*> &list){
    priority_queue<Node*  , vector<Node*> , compare> minHeap;
    int k = list.size();
    if(k == 0){
        return NULL;
    }
    for(int i = 0;i < k;i++){
        if(list[i] != NULL){
            minHeap.push(list[i]);
        }
    }
    Node* head = NULL;
    Node* tail = NULL;


    while(!minHeap.empty()){
        Node* temp = minHeap.top();
        minHeap.pop();
        if(temp->right != NULL){
            minHeap.push(temp);
        }
        if(head == NULL){
            head = temp;
            tail = temp;
            

        }
        else{
            tail->right = temp;
            tail = tail->right;
            
        }



    }
    return head;



}

int main(){

    return 0;
}