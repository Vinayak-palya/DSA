#include<iostream>
using namespace std;
int is_odd(int i){
    if(i%2!=0){
        return 1;
    }
    else return 0;
}
int main(){
    int a,b;
    cin>>a;
    cout<<"\n";
    cin>>b;
    cout<<"odd numbers between "<<a<<" and "<<b<<" are"<<endl;
    for(int i=a;i<=b;i++){
        int x= is_odd(i);
        if(x){
            cout<<i<<" ";
        }
    }
    return 0;
}