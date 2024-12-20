#include<iostream>
using namespace std;
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
void heapify(vector<int> & arr , int size , int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;
    // we have added equals to sign because in case of 0 based indexing
    if(left <= size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr , size , largest);
    }
    return ;
}
vector<int> mergeHeap(vector<int> &a , vector<int> &b , int  n , int m){
    vector<int> ans;
    for(auto i : a){
        ans.push_back(a[i]);
    }
    for(auto j : b){
        ans.push_back(b[j]);
    }
    // step 2 : build heap with merged array
    int size = ans.size();
    for(int i = size/2 - 1;i >= 0;i--){
        heapify(ans , n , i);

    }
    return ans;
}
int main(){

    return 0;
}