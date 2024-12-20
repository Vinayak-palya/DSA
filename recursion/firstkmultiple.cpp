#include<iostream>
using namespace std;
void f(int num,int k){
    if(k == 1){
        cout<<num<<" ";
        return;
    }
    
    f(num,k-1);
    cout<<(num*k)<<" ";
    return;
}
int main(){
    int num,k;
    cin>>num>>k;
    f(num,k);
    return 0;
}