#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"enter no.of rows:"<<endl;
    cin>>n;
    cout<<"enter no. of columns"<<endl;
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}