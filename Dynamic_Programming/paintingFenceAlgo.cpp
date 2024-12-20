#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
int add(int a  , int b)
{
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b)
{
    return ((a%MOD)*1LL * b%MOD)%MOD;  // 1LL
    /*
    Here's why and how you might use 1LL:

Prevent Overflow: When performing arithmetic operations that could potentially
 exceed the range of a regular int, using 1LL ensures that the operation is performed
  using long long int arithmetic. This helps prevent overflow, especially in situations where large numbers are involved.

Correct Type Matching: When you are working with 
functions or operations that expect a long long int type, using 1LL
 makes sure the literal is of the correct type, avoiding implicit type conversions or mismatches.
    */
}
int solve(int n , int k)
{
    if(n == 1)
    return k;
    if(n == 2)
    {
        return add(k , mul(k , k - 1));
    }
    int ans = add(mul(solve(n - 1 , k) , k-1) , mul(solve(n - 2 , k) , k -1));
    return ans;
}
int solveMem(int n , int k , vector<int> & dp)
{
    if(n == 1)
    return k;
    if(n == 2)
    {
        return add(k , mul(k , k - 1));
    }
    if(dp[n] != -1)
    return dp[n];
    dp[n] = add(mul(solveMem(n - 1 , k , dp) , k-1) , mul(solveMem(n - 2 , k , dp) , k -1));
    return dp[n];
}
int solveTab(int n , int k)
{
    vector<int> dp(n+1 , 0);
    dp[1] = k;
    dp[2] = add(k , mul(k , k - 1));

    for(int i = 3;i <= n;i++)
    {
        dp[i] = add(mul(dp[i - 1] , k-1) , mul(dp[i - 2] , k -1));
    }
    return dp[n];
    
    
}
int solveOpt(int n , int k)
{
    int prev2 = k;
    int prev1 = add(k , mul(k , k - 1));
    

    for(int i = 3;i <= n;i++)
    {
        int ans = add(mul(prev1 , k-1) , mul(prev2 , k -1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
    
    
}
int noOfWays(int n , int k)
{
    vector<int> dp(n + 1 , -1);
    return solveMem(n , k , dp);
}
int main (){
    return 0;
}