#include<iostream>
#include<string>

using namespace std;
int longestOnes(string str,int k){
    int start = 0;
    int end = 0;
    int zeros_count = 0;
    int max_L = 0;
    for(;end < str.length();end++){
        if(str[end] == '0'){
            zeros_count ++;
            

        }
        while(zeros_count > k){
                if(str[start] == '0') {
                    zeros_count--;
                    }
                start++;//contracting our window;
            }
            //zeros count <= k
            max_L = max(max_L,end - start + 1);
    }
    return max_L;

}
int main(){
    string str;
    cout<<"enter binary string: ";
    cin>>str;
    int k;
    cin>>k;
    cout<<longestOnes(str,k)<<"\n";
    return 0;
}