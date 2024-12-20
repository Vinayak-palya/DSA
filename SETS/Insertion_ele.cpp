#include<iostream>
#include<set>
using namespace std;

int main(){
    // set <int,greater<int> > set1;
    set<int> set1;
    
    
    set1.insert(3);
    set1.insert(2);
    set1.insert(1);
    set1.insert(4);
    set1.insert(5);
    cout<<set1.size()<<"\n";
    // size remains same because duplicate is added
    // and set contain only unique values

    // traversal in a set
    set<int> :: iterator itr;
    

    for(itr = set1.begin();itr != set1.end();itr++){
        cout<<(*itr)<<" ";

    }cout<<endl;
    // for(auto value : set1){
    //     cout<< value<<" ";
    // }cout<<endl;

    // deletion of elements
    // set1.erase(4);
    auto i = set1.begin();// i is the iterator
    advance(i,3);
    set1.erase(i);
    for(itr = set1.begin();itr != set1.end();itr++){
        cout<<(*itr)<<" ";

    }cout<<endl;
    auto start_itr = set1.begin();
    start_itr++;
    auto end_itr = set1.begin();
    advance(end_itr,3);
    set1.erase(start_itr,end_itr);
    for(itr = set1.begin();itr != set1.end();itr++){
        cout<<(*itr)<<" ";

    }cout<<endl;
    if(set1.find(1) != set1.end()){
        cout<<"Value is present"<<" ";

    }else{
        cout<<"value is not  present"<<endl;

    }


    return 0;
}