#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"enter the no. of rows"<<endl;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int k=i-1;k>=1;k--){
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}