#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &v){
    int n = v.size();
    for(int i = 0;i < n;i++){
        bool flag = true;
        for(int j = 0;j < n-1-i;j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
                flag = false;
            }
            
        }
        if(flag){
            break;
        }
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i <n;i++){
        cin>>v[i];
        
    }
    bubblesort(v);
    for(int i = 0;i < n;i++){
        cout<<v[i]<<" ";
        
    }cout<<endl;
    return 0;
}