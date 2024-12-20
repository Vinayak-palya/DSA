#include<iostream>
#include<vector>
using namespace std;
int factorial(int n){
    int x;
    if(n==1 || n==0){
        return 1;
    }
    else{
        x = n * factorial(n-1);
    }
    return x;
}
int combination(int n,int r){
    int nCr=factorial(n)/factorial(r)/factorial(n-r);
    return nCr;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<combination(i,j)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}