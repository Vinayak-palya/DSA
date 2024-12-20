#include<iostream>
using namespace std;
void swap(int *x , int *y){
    int temp = *x;
    *x = *y;
    // cout<<&x<<&y;
    *y = temp;
    return ;
}
int main(){
    int x = 100;
    int y = 20;
    int *p1=&x;
    int *p2 = &y;
    // cout<<&x<<&y;
    swap(p1,p2);
    cout<<x<<" "<<y;
    return 0;
}