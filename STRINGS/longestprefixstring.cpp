#include<iostream>
#include<vector>
#include<string>
using namespace std;
string LongestCommonPrefix(vector<string> str){
    //sorting the array of strings
    sort(str.begin(),str.end());
    string s2 = str[str.size() - 1];//last string
    string s1 = str[0];
    int i = 0,j = 0;
    string ans = "";
    while(i < s1.size()  &&  j < s2.size()){
        if(s1[i] == s2[j]){
            ans+=s1[i];
            i++;
            j++;
        }
        else break;
    }return ans;
}
int main(){
    int n;
    cout<<"enter no. of strings: ";
    cin>>n;
    cout<<"enter strings :";

    vector<string> str(n);
    for(int i = 0;i < n;i ++){
        cin>>str[i];
    }
    cout<<"longest common prefix:"<<LongestCommonPrefix(str)<<"\n";
    return 0;
}