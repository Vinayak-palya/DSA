#include<iostream>
#include<vector>
#include<list>

using namespace std;
class hashing{
    
    vector<list <int> >hashtable;
    int buckets;
    public:
    hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }
    int hashvalue(int key){
        return key % buckets;//divison method for the hash function

    }
    void addKey(int key){
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);

    }
    list <int> :: iterator searchKey(int key){
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);

    }
    void deleteKey(int key){
        int idx = hashvalue(key);
        if(searchKey(key) != hashtable[idx].end()){//key is present
            hashtable[idx].erase(searchKey(key));
            cout<< key <<" Is deleted"<<"\n";
        }
        else{
            cout<<"key is not present"<<"\n";
        }
       
        
    }


};
int main(){
    hashing h(10);
    h.addKey(5);
    h.addKey(9);
    h.addKey(3);

    h.deleteKey(3);
    return 0;
}