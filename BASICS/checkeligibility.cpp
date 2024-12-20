#include<iostream>
using namespace std;
bool checkeligibility(int age ,int limit){
    if(age>=limit){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int agelimit=18;
    int age=15;
    int is_eligible_for_voting = checkeligibility(age,agelimit);
    if(is_eligible_for_voting){
        cout<<"the current person is eligible for voting"<<endl;
    }
    else{
        cout<<"the current person is not eligible for voting"<<endl;
    }
    return 0;
}