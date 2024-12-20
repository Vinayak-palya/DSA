#include<iostream>
using namespace std;
int main(){
    int arr1[]={1,2,3,4,5,6,7,8,9};
    int n=9;
    int arr2[]={1,2,4,12,7,11,0,8,9};
    int n=9;
    int sum1=0;
    int sum2=0;

    for(int i=0;i<n;i++){
        sum1+=arr1[i];
        

    }
    for(int i=0;i<m;i++){
        sum2+=arr2[i];
    }
    cout<<sum1<<" "<<sum2;//O(n+m)
    return 0;
}