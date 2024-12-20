#include<iostream>
using namespace std;
int main(){
    int i=5;
    while(true){
        if(i%7==0){
            break;
        }
        i+=5;
    }
    cout<<i;
    return 0;
}