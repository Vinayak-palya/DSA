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
int A(int n,int d){
    int sum = 0;
    if(n == 0)  return 0;
    sum += f(n%10,d) + A(n/10,d);
    return sum;
}
int main(){
    int num;
    cin>>num;
    int no_of_digits = 0;
    int temp = num;
    while(temp > 0){
        temp/=10;
        no_of_digits++;
    }
    int x = A(num,no_of_digits);
    if(x == num){
        cout<<"YES"<<"\n";
    }
    else cout<<"NO"<<"\n";
    return 0;
}