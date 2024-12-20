#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int an = mid-l+1;
    int bn = r-mid;
    int a[an],b[bn];
    for(int i = 0;i < an;i++){
        a[i] = arr[l+i];
    }
    for(int i = 0;i < bn;i++){
        b[i] = arr[mid+1+i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < an && j < bn){
        if(a[i]<b[j]){
            arr[k++] = a[i++];

        }
        else arr[k++] = b[j++];
    }
    while(i < an) arr[k++] = a[i++];
    while(i < bn) arr[k++] = b[j++];
    return ;

}
void mergesort(int arr[],int l,int r){
    int mid = (l+r)/2;
    if(l>=r) return ;
    mergesort(arr,0,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return ;
}
int main(){
    int arr[] = {10,28,24,6,34,18,38,44};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}