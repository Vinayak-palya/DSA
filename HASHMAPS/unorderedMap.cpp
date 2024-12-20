#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
int main(){
    unordered_map<int,string> record;
    record.insert(make_pair(1,"chali"));
    record[2] = "bali";
    record[3] = "ghali";
    record[3] = "khali";
    record.insert(make_pair(3,"tali"));
    for(auto pair : record){
        cout<<pair.first << " - "<< pair.second<<endl;
    }cout<<endl;

    return 0;
}