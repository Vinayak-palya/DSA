#include<iostream>
using namespace std;
void fun(int x,int y=100 ,int z=0){
    cout<<x<<" "<<y<<" "<<z<<endl;
}
int main(){
    fun(10,20);
    return 0;
}
