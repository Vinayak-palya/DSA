#include<iostream>
#include<vector>
using namespace std;
void squaresort(vector<int> &v){
    vector<int> ans;
    int left_ptr=0;
    int right_ptr=v.size()-1;
    while(left_ptr<=right_ptr){
        if(abs(v[left_ptr])<abs(v[right_ptr])){
            ans.push_back(v[right_ptr]*v[right_ptr]);
            right_ptr--;
        }
        else{
            ans.push_back(v[left_ptr]*v[left_ptr]);
            left_ptr++;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    squaresort(v);
    
    return 0;
}