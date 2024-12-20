#include<iostream>
using namespace std;
int main(){
    int r1,c1;
    cin>>r1>>c1;
    int a[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    int t[c1][r1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            t[j][i]=a[i][j];
        }
    }
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}