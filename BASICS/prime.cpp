#include<iostream>
#include<math.h>
using namespace std;
int is_prime(int i){
    int k=0;
    for(int a=2;a*a<=i;a++){
        if(i%a==0) k++;

    }
    if(k==0){
        return 1;
    }
    else return 0;
}
int main(){
    int a,b;
    cin>>a;
    cout<<"\n";
    cin>>b;
    cout<<"prime numbers between "<<a<<" and "<<b<<" are"<<endl;
    for(int i=a;i<=b;i++){
        int x= is_prime(i);
        if(x){
            cout<<i<<" ";
        }
    }
    return 0;
}