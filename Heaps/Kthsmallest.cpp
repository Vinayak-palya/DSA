#include<iostream>
#include<queue>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size = 0;
        arr[0] = -1;
    }
    void Insert(int val){
        size++;
        arr[size] = val;
        int index = size;
        while(index < size){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i = 0;i < size;i++){
            cout << arr[i] << " ";
        }
        return ;
    }
    void deleteFromHeap(){
        if(size == 0){
            cout << "Nothing to delete" << endl;
            return ;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size){
            // for 0 based indexing
            int left_child = 2 *i;
            if(left_child < size && arr[left_child] > arr[i]){
                swap(arr[i] , arr[left_child]);
                i = left_child;
            }
            int right_child = 2*i + 1;
            if(right_child < size && arr[right_child] > arr[i]){
                swap(arr[i] , arr[right_child]);
                i = right_child;
            }
            else{
                return ;
            }

        }
    }
};
void heapify(int arr[] , int size , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left < size && arr[left] > arr[largest]){
        largest = left;

    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr, size  , largest);
    }
    return ;
}
int kthSmallest(int arr[] , int l, int r , int k){
    // l represents the starting and r reperesents the ending index of the array
    priority_queue < int > pq;
    // step1
    for(int i = l;i < k + l;i++){
        pq.push(arr[i]);
    }
    // step2
    for(int i = l + k;i < r; i++){
        if(pq.top() < arr[i]){
            pq.pop();
            q.push(arr[i]);
        }
    }
    int ans = pq.top();
    return ans;
}
int main(){
    return 0;
}