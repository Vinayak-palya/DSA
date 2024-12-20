#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    cout<<"enter two integers:";
    cin>>n1>>n2;
    cout<<"enter an operator(+,-,%,/,*):";
    char op;
    cin>>op;
    switch (op){
        case '+':
        cout<<"sum is: "<<(n1+n2);
        break;
        case '-':
        cout<<"difference is: "<<(n1-n2);
        break;
        case '*':
        cout<<"multiplication is: "<<n1*n2;
        break;
        case '/':
        cout<<"division is: "<<n1/n2;
        break;
        case '%':
        cout<<"remainder is :"<<n1%n2;
        break ;
        default :
        cout<<"invalid";
    
    }
    return 0;
}