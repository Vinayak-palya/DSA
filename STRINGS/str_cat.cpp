#include<iostream>
#include<string>
using namespace std;
int main(){
    char s1[20] = "college ";
    char s2[20] = "wallah";
    strcat(s1,s2);
    cout<<s1<<endl;
    return 0;
}