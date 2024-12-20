#include<iostream>
using namespace std;
int sum_In_range(int x,int y){
    int result=0;
    for(int i=x;i<=y;i++){
        result+=i;

    }
    return result;
}
int sum_In_range_optimised(int x,int y){
    int n=y-x+1;
    int a=x;
    int d=1;
    int result= (n * (2*a + (n-1)*d))/2;
    return result;

}
int main(){
    cout<<sum_In_range(2,6)<<"\n";
    cout<<sum_In_range_optimised(2,6)<<"\n";

    return 0;
}