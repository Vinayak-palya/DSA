#include<iostream>
#include<string>
#include<vector>
using namespace std;
string count(string str){
    vector<int> freq(26,0);
    //frequency array;
    for(int i = 0;i < str.length();i++){
        int index = str[i] - 'a';
        freq[index]++;
    }
    int j = 0;
    for(int i = 0;i < 26;i++){
        while(freq[i]--){
            str[j++] = i + 'a'; 
        }
    }
    return str;

}
int main(){
    string str;
    cin>>str;
    cout<<count(str)<<endl;
    return 0;
}