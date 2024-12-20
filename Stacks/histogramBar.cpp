#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int histogram(vector<int> &arr){
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    int ans = INT_MIN;

    st.push(0);
    for(int i = 1;i < n;i++){
        while(!st.empty()  and  arr[i] < arr[st.top()]){
            int el = arr[st.top()];//current bar  to be removed
            st.pop();
            int nsi = i;
            int psi = (st.empty())? (-1) : st.top();
            ans = max(ans,el*(nsi - psi - 1));
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        int el = arr[st.top()];
        st.pop();
        int nsi = n;
        int psi = st.empty()? (-1) : st.top();
        ans = max(ans,el*(nsi - psi - 1));

        st.pop();
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int ans = histogram(v);
    cout << ans << "\n";
    return 0;
}