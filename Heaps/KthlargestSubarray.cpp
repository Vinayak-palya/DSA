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
int getKthLargest(vector <int> &arr , int k){
    vector<int> sumStore;
    int n = arr.size();
    for(int i = 0;i < ;i++){
        int sum = 0;
        for(int j = i;j < n;j++){
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin() , sumStore.end());
    return sumStore[sumStore.size() - k];

}
int getKthLargestOpt(vector<int> &arr , int k){
    priority_queue<int , vector<int> , greater<int> >mini;
    
    int n = arr.size();
    for(int j = 0;j < n;j ++){
        int sum = 0;
        for(int i = 0; i < n;i ++){
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }
            else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}
int main(){

    return 0;
}