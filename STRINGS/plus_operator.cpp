#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1 = "college ";
    string s2 = "wallah";
    
    // cout<<s1+s2<<"\n";
    s1+=s2;//s1 = s1 + s2 and s1+=s2 both the statement are not same
    cout<<s1<<" ";
    return 0;
}