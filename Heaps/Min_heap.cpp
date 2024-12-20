#include<iostream>
#include<vector>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    void Insert(int val){
        size++;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[index] > arr[parent]){
                swap(arr[index] , arr[parent]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i = 1;i < size;i++){
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    void deleteFormHeap(){
        if(size == 0){
            cout << "Nothing to delete" << endl;
            return ;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size){
            int left = 2 * i;
            int right = 2 * i + 1;
            if(left < size && arr[i] < arr[left]){
                swap(arr[left] , arr[i]);
                i = left;
            }
            if(right < size && arr[i] < arr[right]){
                swap(arr[right] , arr[i]);
                i = right;
            }
            else{
                return ;
            }
        }
    return ;
    }
};
// for heapifying the  max heap 
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
            heapify(arr , size , largest);
        }
    
    return ;
}
void heapifyMin(vector<int> & arr , int size , int i){
    int smallest = i;
    int left = 2*i+ 1;
    int right = 2*i + 2;
        if(left < size && arr[left] < arr[smallest]){
            smallest = left;
        }
        if(right < size && arr[right] < arr[smallest]){
            smallest = right;
        }
        if(smallest != i){
            swap(arr[smallest] , arr[i]);
            heapifyMin(arr , size , smallest);
        }
    
    return ;
}
vector<int> buidMinHeap(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2 - 1;i >= 0;i--){
        heapifyMin(arr , n , i);
    }
    return  arr;
}

int main(){

    return 0;
}