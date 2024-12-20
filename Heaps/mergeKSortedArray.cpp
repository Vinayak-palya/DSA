#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data;
    int i;
    int j;
    Node(int val , int row , int coln){
        data = val;
        i = row;
        j = coln;
        
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
vector <int> mergeKsortedArrays(vector<vector<int> >&kArrays , int k){
    priority_queue<Node* , vector<Node*>  , compare> minHeap;
    // step1 saare arrays ke first element ko minHeap main push karna hai
    for(int i = 0;i < k;i++){
        Node* temp = new Node(kArrays[i][0] , i , 0);
        minHeap.push(temp);
    }
    // step 2
    vector<int> ans;
    while(minHeap.size() > 0){
        Node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int i = temp->i;
        int j = temp->j;

        if(j + 1 < kArrays[i].size()){
            Node* next = new Node(kArrays[i][j+1] , i , j+1);
            minHeap.push(next);
        }
    }
}
int main(){

    return 0;
}