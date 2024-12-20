#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter odd number:";
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     if(i!=(n+1)/2){
    //         for(int j=1;j<=(n-1)/2;j++){
    //         cout<<"  ";
    //         }
    //         cout<<"*";
    //     }
    //     else{
    //         for(int k=1;k<=n;k++){
    //             cout<<"* ";
    //         }
    //     }
    //     cout<<endl;
    // }
    //alternative
    for(int line=0;line<n;line++){
        for(int i=0;i<n;i++){
            if(i==n/2){
                cout<<"*";
            }
            else if (line==n/2){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}