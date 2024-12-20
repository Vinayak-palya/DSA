#include<iostream>
#include<vector>
using namespace std;
void f(string s,int i,string s1,int n){
    if(i == n) {
        cout<<s1<<" ";
        return ;
    }
    
    f(s,i+1,s1+s[i],n);
    f(s,i+1,s1,n);
    return ;
}
int main(){
    int n;
    
    string s = "bcd";
    n = s.length();
    string s1 = "";
    f(s,0,s1,n);
    return 0;
}