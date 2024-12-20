#include<iostream>
#include<vector>

using namespace std;
void Insertionsort(vector<int> &v){
    int n = v.size();
    for(int i = 0;i < n;i++){
        int current = v[i];
        int j = i-1;
        while(v[j] > current  &&  j>=0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    Insertionsort(v);
    for(int i = 0;i < n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
