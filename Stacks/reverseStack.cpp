#include<iostream>
#include<stack>
using namespace std;
void InsertAtBottom_one(stack<int> &st,int x){
    stack<int> temp;
    while(not st.empty()){
        temp.push(st.top());
        st.pop();
        
    }
    st.push(x);// this is the point when all the data 
    while(not temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    

}
void InsertAtBottom_second(stack <int> &input,int x){
    if(input.empty()){
        input.push(x);
        return ;
    }
    int curr = input.top();
    input.pop();
    InsertAtBottom_second(input,x);
    input.push(curr);
    return;
}

void reverse_one(stack<int> &input){
    stack<int> t1,t2;
    while(not input.empty()){
        t1.push(input.top());
        input.pop();
    }
    while(not t1.empty()){
        t2.push(t1.top());
        t1.pop();
    }
    while(not t2.empty()){
        input.push(t2.top());
        t2.pop();
    }
    return ;

}
void f(stack<int> & input){
    if(input.empty()) return ;
    int curr = input.top();
    input.pop();
    f(input);
    InsertAtBottom_one(input,curr);
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse_one(st);
    while(not st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}