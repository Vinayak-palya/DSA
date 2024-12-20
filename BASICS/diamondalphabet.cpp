#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=2*n-1;i++){
        int a=i;
        if(i<=n){
             for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
            for(int j=1;j<=2*i-1;j++){
            cout<<(char)(j+64);
            cout<<" ";
            }
        }
        else{
            for(int k=1;k<=i-n;k++){
                cout<<"  ";
            }         
            for(int l=1;l<=2*(2*n-i)-1;l++){
                cout<<(char)(l+64);
                cout<<" ";
            }
            // int p=2;
            // a-=p;
            // p+=2;
            
        }
        cout<<endl;
    }

    // }
    // char ch='a';
    // int x=ch+1;
    // cout<<(char)x<<"\n";
    return 0;
}