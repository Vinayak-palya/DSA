#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n,m;
    vector<int> v1(n);
    vector<int> v2(m);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>v1[i];

    }
    for(int i=0;i<m;i++){
        cin>>v2[i];
        
    }
    int i=0;
    int j=0;
    int k=0;
    vector<int> v3(m+n);
    
        for(;i<n,j<m;){
            
                if(v1[i]<v2[j]){
                    v3[k++]=v1[i++];   
                }
                
                else {
                    v3[k++]=v2[j++];
                    
                }
            }
    while(i<n){
        v3[k++] = v1[i++];
    }
    while(k<m){
        v3[k++] = v2[j++];
    }



    for(int i=0;i<m+n;i++)
{
    cout<<v3[i]<<" ";
}        
    

    return 0;
}