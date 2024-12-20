#include <iostream>
#include <stack>
using namespace std;
/*
space complexity = O(n)
time complexity = O(n)
*/
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

int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    InsertAtBottom_one(st,100);
    // InsertAtBottom_second(st,100);
    while(not st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}