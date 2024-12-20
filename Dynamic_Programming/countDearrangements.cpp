#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
int solveMem(int n , vector<long long int> &dp)
{
    // base case
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    if(dp[n] != -1)
    return dp[n];
    dp[n] = (((n -1)%MOD )* ((countDearrangements(n - 1) %MOD)+ (countDearrangements(n - 2)%MOD)))%MOD;
    return dp[n];
}
int solveTab(int n)
{
    vector<long long int> dp(n+1 , 0);
    // base case
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3;i <= n;i++)
    {
        long long int first = dp[i - 1]%MOD;
        long long int second = dp[i - 2]%MOD;
        long long int sum = (first+ second)%MOD;
        long long int ans = ( (i -1)*sum)%MOD;
        dp[i] = ans;


    }
    
    return dp[n];
}
int solveOpt(int n)
{
    vector<long long int> dp(n+1 , 0);
    // base case
    long long int prev2 = 0;
    long long int prev1 = 1;
    
    for(int i = 3;i <= n;i++)
    {
        long long int first = prev1%MOD;
        long long int second = prev2%MOD;
        long long int sum = (first+ second)%MOD;
        long long int ans = ( (i -1)*sum)%MOD;
        prev2 = prev1;
        prev1 = ans;


    }
    
    return prev1;
}

long long int countDearrangements(int n)
{
    // base case
    if(n == 1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    int ans = (((n -1)%MOD )* ((countDearrangements(n - 1) %MOD)+ (countDearrangements(n - 2)%MOD)))%MOD;
    return ans;
}
int main (){
    return 0;
}