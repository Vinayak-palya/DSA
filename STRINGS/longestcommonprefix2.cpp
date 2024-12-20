#include<iostream>
#include<vector>
#include<string>
using namespace std;
string LongestCommonPrefix(vector<string> str){
    //keeping first string as constant
    string s1 = str[0];
    int ans_len = s1.size();
    
    for(int i = 1;i < str.size();i++){
        int j = 0;
        while(j < s1.size() && j < str[i].size()  &&  s1[j] == str[i][j]){//finding common prefix string length
            j++;
            
        }
        ans_len = min(ans_len,j);//updating length of answer string
    } 
    
    string ans = s1.substr(0,ans_len);
    return ans;

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