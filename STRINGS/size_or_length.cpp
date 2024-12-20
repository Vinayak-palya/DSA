#include<iostream>
#include<string>
using namespace std;
int main(){
    int num = 432;

    string s1 = to_string(num);
    s1+="1";
    cout<<s1<<endl;
    return 0;
}