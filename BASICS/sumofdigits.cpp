#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    while(n>0){
        int k=n%10;
        sum+=k;
        n=n/10;
    }
    cout<<sum;
    return 0;
}