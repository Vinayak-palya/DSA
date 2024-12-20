#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &v,int n){
    for(int i = 0;i < n-1;i++){
        bool flag  = false;
        for(int j = 0;j < n-i-1;j++){
            if(v[j]>v[j+1]){
                flag = true;
                swap(v[j],v[j+1]);
            }

        }
        if(!flag){
            break;

        }
    }
    return ;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    bubblesort(v,n);
    for(int i = 0;i < n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
