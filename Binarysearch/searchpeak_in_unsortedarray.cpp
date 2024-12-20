#include<iostream>
#include<vector>
using namespace std;
int findpeaks(vector<int> &input){
    int n = input.size();
    int lo = 0,hi = n - 1;
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(mid == 0){
            if(input[mid] > input[mid+1]){
                return 0;

            }
            else{
                return 1;

            }

        }
        else if(mid == n-1){
            if(input[mid] > input[mid - 1]){
                return mid;
            }
            else{
                return mid - 1;
            }
        }
        else{
            if(input[mid] > input[mid +1]  &&  input[mid] > input[mid - 1]){
                return mid;
            }
            else if(input[mid] > input[mid - 1]){
                lo = mid + 1;
            }
            else{
                hi  = mid - 1;
            }
        }
    }


return ans ;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    cout<<findpeaks(v)<< " ";
    return 0;
}