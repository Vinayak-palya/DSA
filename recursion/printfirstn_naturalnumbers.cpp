#include<iostream>
using namespace std;
void f(int n){
    //base case
    if(n<1){
    return;
    }
    //go and print first n natural number
    f(n-1);
    cout<<n<<" ";
    return ;
}
int main(){
    int n;
    cin>>n;
    f(n);
    return 0;
}