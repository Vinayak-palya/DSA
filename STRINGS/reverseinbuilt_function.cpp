#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "hello";
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    
    return 0;
}