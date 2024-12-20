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
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>v[i][j];

    //     }
    // }
    int value=1;
    while(maxr >= minr && maxc >= minc){
    for(int i=minc; i <= maxc ;i++){
        v[minr][i]=value;
        value++;
    }
    minr++;
    for(int i=minr;i <= maxr;i++){
        v[i][maxc]=value;
        value++;
        
    }
    maxc--;
    if(minr<=maxr){
    for(int i=maxc;i>=minc;i--){
        v[maxr][i]=value;
        value++;
        
    }
    maxr--;
    }
    if(minc<=maxc){
    for(int i=maxr;i>=minr;i--){
        v[i][minc]=value;
        value++;
        
    }
    minc++;
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";

        }
        cout<<"\n";
    }
    return 0;

}
