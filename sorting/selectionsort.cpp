#include<iostream>
#include<vector>
using namespace std;
void selectionsort(vector<int> &v){
    int n=v.size();
    for(int i = 0;i < n-1;i++){
        int min_idx = i;
        for(int j = i+1;j < n;j++){
            if(v[j] < v[min_idx]){
                min_idx = j;
            }
            
        }
        if(min_idx!=i){
                swap(v[i],v[min_idx]);
            }
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < v.size();i++){
        cin>>v[i];
    }
    selectionsort(v);
    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<" ";
    } cout<<endl;

    return 0;
}
