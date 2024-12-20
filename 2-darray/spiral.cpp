#include<iostream>
#include<vector>
using namespace std;
int main(){
    int maxr,minr,maxc,minc;
    minr=0;
    minc=0;
    int n,m;
    cin>>n>>m;
    maxr=n-1;
    maxc=m-1;
    vector<vector<int> > v(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];

        }
    }
    while(maxr >= minr && maxc >= minc){
    for(int i=minc; i <= maxc ;i++){
        cout<<v[minr][i]<<" ";
        
    }
    minr++;
    for(int i=minr;i <= maxr;i++){
        cout<<v[i][maxc]<<" ";
        
    }
    maxc--;
    if(minr<=maxr){
    for(int i=maxc;i>=minc;i--){
        cout<<v[maxr][i]<<" ";
        
    }
    maxr--;
    }
    if(minc<=maxc){
    for(int i=maxr;i>=minr;i--){
        cout<<v[i][minc]<<" ";
        
    }
    minc++;
    }
    }
    return 0;

}
