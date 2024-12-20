#include<iostream>
#include<map>
using namespace std;
int main(){
    map < string , int , greater < string > > directory;
    directory["naman"] = 32456;
    directory["aman"] = 12345;
    directory["chaman"] = 23456;
    // for(auto ele : directory){
    //     cout<<ele.first<<" -> ";
    //     cout<< ele.second<<endl;

    // } cout<<endl;

    directory["chaman"] = 98765;
    directory.insert(make_pair("chaman",23567));// it will not do anything because chaman is a;ready initialized
    for(auto ele : directory){
        cout<<ele.first<<" -> ";
        cout<< ele.second<<endl;

    }
    map< string,int> :: reverse_iterator itr;
    for(itr = directory.rbegin();itr != directory.rend();itr++){
        cout<<itr->first<<" -> "<<itr->second<<endl;
    }

    return 0;
}