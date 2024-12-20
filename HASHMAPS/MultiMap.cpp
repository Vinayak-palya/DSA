#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string,int>  directory;
    directory.insert(make_pair("urvi",30185));
    directory.insert(make_pair("saghvi",345845));
    directory.insert(make_pair("saghvi",9000000));
    // directory["urvi"] = 46830; it will throw  an error because we cannot use square bracket in multi map
    for(auto pair : directory){
        cout<<"Name"<<" - "<< pair.first<<endl
            <<"phone no."<<" - "<<pair.second<<endl;
    }

    cout<<directory.count("saghvi")<<endl;
    
    return 0;
}