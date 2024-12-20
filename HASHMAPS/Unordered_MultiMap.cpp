#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap<string,int> fruit;
    fruit.insert(make_pair("apple",6));
    fruit.insert(make_pair("banana",4));
    fruit.insert(make_pair("mango",5));
    fruit.insert(make_pair("apple",3));
    for(auto count: fruit){
        cout<<"Fruit - "<<count.first<<endl
            <<"no. - " << count.second<<endl;
    }
    return 0;
}