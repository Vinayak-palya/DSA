#include<iostream>
using namespace std;
int main(){
    int r1,cr,c2;
    cin>>r1>>cr>>c2;
    int A[r1][cr];
    int B[cr][c2];
    int res[r1][c2];
    for(int i=0;i<r1;i++){
        for(int j=0;j<cr;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<cr;i++){
        for(int j=0;j<c2;j++){
            cin>>B[i][j];
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            res[i][j]=0;
            for(int k=0;k<cr;k++){
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}