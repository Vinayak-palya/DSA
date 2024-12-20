#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int rd=0;
    while(n>0){
        int k=n%10;
        rd=rd*10+k;
        n/=10;
    }
    cout<<rd;
    return 0;
}