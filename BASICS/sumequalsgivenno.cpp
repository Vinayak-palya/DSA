#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int x;
    cout<<"enter the no.";
    cin>>x;
    int a=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(v[i]+v[j]==x){
    //             a++;
    //             break;

    //         }
            
            
    //     }
    // }
    // if(a==0){
    //     cout<<"no";
        
    // }
    // else cout<<"yes";
    int leftptr=0;
    int rightptr=v.size()-1;
    bool flag=false;
    while(leftptr < rightptr){
        if(v[leftptr]+v[rightptr] < x){
            leftptr++;
            
        }
        else if(v[leftptr]+v[rightptr] > x){
            rightptr--;
            
        }
        else{
            flag = true;
            break;
        }
    }
    if(flag==true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}