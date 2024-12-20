#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    //for loop
    for(int i=0;i<5;i++){
        int elements;
        cin>>elements;
        v.push_back(elements);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "; 
    }

    cout<<endl; 
    v.insert(v.begin()+2,6);

    //for each loop
    for(int elements:v){
        cout<<elements<<" ";
    }
    cout<<endl;
    v.erase(v.end()-2);
    int idx=0;
    while(idx<v.size()){
        cout<<v[idx++]<<" ";
    }
    return 0;
}