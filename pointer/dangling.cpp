#include<iostream>
using namespace std;
int main(){
    int *ptr = NULL;
    {
        int x=10;
        ptr = &x;

    }
    cout<<ptr;
    return 0;
}