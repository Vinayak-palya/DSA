#include<iostream>
#include<stack>
using namespace std;
void InsertAtIdx(stack<int> &st,int idx){
    stack<int> temp;
    int n = st.size();
    int count = 0;
    while(count < n - idx - 1){
        count++;
        temp.push(st.top());
        st.pop();

    }
    st.pop();
    while(not temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // InsertAtBottom(st,100);
    InsertAtIdx(st,1);
    while(not st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}