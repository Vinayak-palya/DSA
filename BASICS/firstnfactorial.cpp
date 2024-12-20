#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int l;
    int factorial=1;;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            factorial*=k;
            l=k;
        }
        cout<<"factorial of"<<l<<"is"<<factorial<<endl;
        factorial=1;
    }
    return 0;
}