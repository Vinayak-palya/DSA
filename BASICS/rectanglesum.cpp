#include<iostream>
using namespace std;
int rectanglesum(vector<vector<int> > &matrix,int  l1,int r1,int l2,int r2){
    int sum=0;
    // for(int i=l1;i<=l2;i++){
    //     for(int j=r1;j<=r2;j++){
    //         sum+=matrix[i][j];
    //     }
    // }
    //prefix sum array row wise
    for(int i=0;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }
    for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            matrix[i][j]+=matrix[i-1][j];
        }
    }
    int topsum=0,leftsum=0,topleftsum=0;
    if(l1!=0) topsum=matrix[l1-1][r2];
    if(r1!=0) leftsum=matrix[l2][r1-1];
    if(l1!=0 && r1!=0)  topleftsum=matrix[l1-1][r1-1];
    sum+=(matrix[l2][r2]-topsum-leftsum+topleftsum);

//     for(int i=l1;i<=l2;i++)
// {
//     if(r1!=0){
//         sum+=(matrix[i][r2]-matrix[i][r1-1]);
//     }
//     else{
//         sum+=matrix[i][r2];
//     }
    
// }    
return sum;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];

        }
    }
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
            
        }cout<<"\n";
    }


    int sum = rectanglesum(matrix,l1,r1,l2,r2);
    cout<<"sum:"<<sum<<"\n";


    return 0;
}