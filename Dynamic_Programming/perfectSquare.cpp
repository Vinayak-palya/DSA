#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int solve(int n)
{
    // base case
    if(n == 0)
    {
        return 0;
    }

    int ans = n;
    for(int i = 1;i*i <= n;i++)
    {
        ans = min(ans, 1 + solve(n - i*i));
    }
    return ans;
}
int solveMem(int n , vector<int> & dp)
{
    // base case
    if(n == 0)
    {
        return 0;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for(int i = 1;i*i <= n;i++)
    {
        ans = min(ans, 1 + solveMem(n - i*i , dp));
    }
    dp[n] = ans;
    return dp[n];
}

int solveTab(int n )
{
    vector<int> dp(n + 1 , INT_MAX);
    // base case
    dp[0] = 0;
    if(dp[n] != -1)
    {
        return dp[n];
    }

    
    for(int i = 0;i <= n;i++)
    {
        for(int j = 1;j*j <= n;j++)
        {
            int temp = j*j;
            if(i- j*j >= 0)
            dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
    }
    
    return dp[n];
}


int minSquares(int n)
{

}
int main (){
    return 0;
}