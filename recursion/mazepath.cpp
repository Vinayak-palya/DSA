#include<iostream>
using namespace std;
int f(int i,int j,int m,int n){
    if(i == m-1  && j == n-1){
        return 1;
    }
    // else if(i == m-1){
    //     return f(i,j+1,m,n);
    // }
    // else if(j == n-1){
    //     return f(i+1,j,m,n);
    // }
    if(i >= m || j >= n){
        return 0;
    }
    return f(i+1,j,m,n) + f(i,j+1,m,n);
}
int main(){
    cout<<f(0,0,2,3);
    return 0;
}