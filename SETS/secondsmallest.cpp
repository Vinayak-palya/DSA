#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];

    }
    set<int> s;
    for(int i = 0;i < n;i++){
        s.insert(v[i]);
    }
    set<int>  :: iterator itr = s.begin();
    

    advance(itr,1);
    cout<< "Second smallest number is : "<<(*itr)<<endl;
    return 0;
}