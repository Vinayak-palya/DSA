#include<iostream>
using namespace std;
bool f(int num,int *temp){

    
    if(num>=0 and num<=9){
        int lastdigit = (*temp)%10;
        *temp/=10;
        return (num == lastdigit);
    }


    bool result = (f(num/10,temp) and (num%10) == ((*temp) %10));
    *temp/=10;
    return result;
}
int main(){
    int num =12;
    int anothernum = num;
    int *temp = &anothernum;

    cout<<f(num,temp);
    return 0;
}