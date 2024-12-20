#include <iostream>
#include <stack>
using namespace std;
/*
space complexity = O(n)
time complexity = O(n)
*/
void InsertAtBottom(stack<int> &st){
    stack<int> temp;
    while( st.size() != 1){
        temp.push(st.top());
        st.pop();
        
    }
    st.pop();
    
    while(not temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    

}
void f(stack <int> &input){
    if(input.size() == 1){
        input.pop();
        return ;
    }
    int curr = input.top();
    input.pop();
    f(input);
    input.push(curr);
    return;
}

int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    InsertAtBottom(st);
    // f(st);
    while(not st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}