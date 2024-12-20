#include<iostream>

#include<stack>
using namespace std;
class Queue{
    stack<int> st;
    public:
    Queue(){}
    void push(int x){
        st.push(x);
        //time -- > O(1);


    }
    void pop(){
        stack<int> tm;
        if(st.empty()) return ;
        while(st.size() > 1){
            tm.push(st.top());
            st.pop();
        }
        st.pop();
        while(!tm.empty()){
            st.push(tm.top());
            tm.pop();
        }

         
    }
    bool empty(){
        return st.empty();
    }
    int front(){
         stack<int> tm;
        if(st.empty()) return -1;
        while(st.size() > 1){
            tm.push(st.top());
            st.pop();
        }
        int result = st.top();
        while(!tm.empty()){
            st.push(tm.top());
            tm.pop();
        }

         
        return result;
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