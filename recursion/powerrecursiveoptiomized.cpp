#include<iostream>
using namespace std;
int f(int p,int q){
    if(q == 0){
        return 1;
    }
    else if (q%2 != 0){
        int result = f(p,(q-1)/2);
        return result*result*p;
    }
   else {
    int result = f(p,q/2);
    return result*result;
   }
}
int main(){
    int result = f(2,3);
    cout<<result<<" ";
    return 0;
}