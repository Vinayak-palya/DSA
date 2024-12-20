#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1 {1,2,3,4};
    // auto itr = l1.begin();
    // l1.begin will give the iterator pointing to the begining 
    // l1.end() will give the iterater pointing to the end; 
    // list <int> ::iterator itr = l1.begin();
    // auto rev_itr = l1.rbegin();
    // cout<<*rev_itr<<endl;
    // cout<< *itr << endl;
    // advance(itr,2);
    // cout<< *itr << endl;



    // for(auto num:l1){
    //     cout<<num<<endl;
    // }
    // using iterators
    // for(auto itr = l1.begin(); itr != l1.end();itr++){
    //     cout<<*itr<<"\n";

    // }cout<<endl;


    // reverse traveral
    for(auto itr = l1.rbegin(); itr != l1.rend();itr++){
        cout<< *itr<<endl;
    }

    //inserting elements
    // auto itr = l1.begin();
    // advance(itr,2);
    // l1.insert(itr,5);
    // for(auto itr = l1.begin(); itr != l1.end();itr++){
    //     cout<<*itr<<"\n";
    // }
    // l1.insert(itr,3,5);
    // for(auto itr = l1.begin(); itr != l1.end();itr++){
    //     cout<<*itr<<"\n";
    // }
    // auto l = l1.begin();
    // auto r = l1.begin();
    // advance(r,2);
    // l1.insert(itr,l,r);


    //1 2 1 2 3 4
    auto s_itr = l1.begin();
    advance(s_itr,2);// s_itr pointing to 2;
    auto e_itr = l1.begin();
    advance(e_itr,4);
    l1.erase(s_itr,e_itr);
    



    return 0;
}