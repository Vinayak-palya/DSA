#include<iostream>
#include<vector>
using namespace std;
int fibonacci(int n , vector<int>& dp){
    if(n <= 1)
    return n;
    if(dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fibonacii(n - 1 , dp) + fib(n - 2 , dp);
    return dp[n];
}
int main (){

    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i = 0;i < n + 1;i++)
    {
        dp[i] = -1;
    }
    fibonacci(n , dp);

    return 0;
}