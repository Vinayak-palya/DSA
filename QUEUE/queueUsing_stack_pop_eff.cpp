#include<iostream>

#include<stack>
using namespace std;
class Queue{
    stack<int> st;
    public:
    Queue(){}
    void push(int x){
       stack<int> tmp;
       while(not st.empty()){
        tmp.push(st.top());
        st.pop();
       }
       st.push(x);
       while(! tmp.empty()){
        st.push(tmp.top());
        tmp.pop();
       }
       // time -->O(n);
    }
    void pop(){
        if(st.empty()) return;
        st.pop();
        //time -->O(1);

    }
    bool empty(){
        return st.empty();
    }
    int front(){
        if(st.empty()) return -1;
        return st.top();
    }
};
int main(){
    Queue qu;
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