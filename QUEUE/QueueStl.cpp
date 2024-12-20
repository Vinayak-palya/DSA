#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    while(not qu.empty()){
        cout<<qu.front()<<"\n";
        qu.pop();
    }
    return 0;
}