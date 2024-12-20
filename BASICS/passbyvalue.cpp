#include<iostream>
using namespace std;
void swap(int x,int y){
    int temp=x;
    x=y;
    y=temp;
}
int main(){
    int i = 6,j = 4;
    swap(i,j);
    cout<<i<<" "<<j<<"\n";
    return 0;
}