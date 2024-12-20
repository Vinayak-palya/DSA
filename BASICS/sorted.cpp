#include<iostream>
#include<vector>
using namespace std;
int main(){
    int array[]={1,2,3,7,5,6};
    bool flag=true;
    for(int i=1;i<sizeof(array)/sizeof(array[0]);i++){
        if(array[i]<=array[i-1]){
            flag=false;
        }
    }
    cout<<flag<<endl;
    return 0;
}