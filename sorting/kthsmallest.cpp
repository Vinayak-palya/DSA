#include<iostream>
#include<climits>
using namespace std;
int partition(int arr[],int f,int l){
    int i = f-1;
    int pivot = arr[l];
    for(int j = f;j < l;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}
int kthsmallest(int arr[],int f,int l,int k){
    if(k > 0 && k <= l-f+1){
        
        int pos = partition(arr,f,l);
        
        if(pos-f == k-1){
            return arr[pos];
        }
        else if (pos - f > k - 1){
            return kthsmallest(arr,f,pos-1,k);
        }
        else{
            return kthsmallest(arr,pos+1,l,k-(pos-f+1));
        }
        
    }
    return INT_MAX;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<"kth smallest element in an array = "<<kthsmallest(arr,0,n-1,k);
    return 0;
}