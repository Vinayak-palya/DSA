#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<sqrt(n);j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
//total case -->n*sqrt(n)
//worst case--> O(nsqrt(n))