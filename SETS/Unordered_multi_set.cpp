#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_multiset<int> ums;
    ums.insert(4);
    ums.insert(8);
    ums.insert(3);
    ums.insert(1);
    ums.insert(4);
    for(int value:ums){
        cout<<value<<" ";
    }cout<<endl;
    
    return 0;

}