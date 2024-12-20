#include<iostream>
#include<math.h>
using namespace std;
void fun(string);

int addition(int ,int );
int main(){
   fun("sanket");
   int response = addition(8,7);
   cout<<response;
    
    return 0;
}
void fun(string name){
    cout<<"ARE YOU HAVING FUN "<<name<<"?"<<endl;
}
int addition(int x,int y){
    //processing 
    int result =  x + y;
    cout<<sqrt(result)<<"\n";
    return result;
}