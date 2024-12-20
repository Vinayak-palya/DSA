#include<iostream>
using namespace std;
void rotate(vector<vector<int> > &v,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            // int temp=v[i][j];
            // v[i][j]=v[j][i];
            // v[j][i]=temp;
            swap(v[i][j],v[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0,k=n-1;j<k;j++,k--){
            // int temp=v[i][j];
            // v[i][j]=v[i][k];
            // v[i][k]=temp;
            swap(v[i][k],v[i][j]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];

        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         int temp=v[i][j];
    //         v[i][j]=v[j][i];
    //         v[j][i]=temp;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0,k=n-1;j<k;j++,k--){
    //         int temp=v[i][j];
    //         v[i][j]=v[i][k];
    //         v[i][k]=temp;
    //     }
    // }
    rotate(v,n);
    for(int i=0;i<v.size();i++){
        for(int k=0;k<v[i].size();k++){
            cout<<v[i][k]<<" ";
        } cout<<endl;
    }
    return 0;
}