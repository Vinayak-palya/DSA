#include<iostream>
using namespace std;
string name="vinayak";//global
void fun(){
    int x=10;
    for(int y=0;y<5;y++){
        x=x+y;
        int z=x*x;
    }
    // cout<<x<<" "<<y<<" "<<z;
    cout<<name<<endl;
}
int main(){
    
    cout<<name<<endl;
    name="sathak";//
    fun();
    
    return 0;
}