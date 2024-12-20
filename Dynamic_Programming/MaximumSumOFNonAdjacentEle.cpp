#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> & nums , int n)
{
    // Base case
    if(n < 0)
    {
        return 0;
    }
    if(n == 0) return nums[0];

    int inclu = solve(nums , n - 2 ) + nums[n];
    int exclu = solve(nums , n - 1) + 0;
    return max(inclu , exclu);

}
int solveMem(vector<int> & nums , int n , vector<int> & dp)
{
    //  base case
    if(n < 0)
    return 0;
    if(n == 0 )
    return nums[n];
    if(dp[n] != -1)
    {
        return dp[n];
    }
    int inclu = solveMem(nums , n - 2 ) + nums[n];
    int exclu = solveMem(nums , n - 1) + 0;
    dp[n] = max(inclu , exclu);
    return dp[n];

}
int solveTab(vector<int> & nums)
{
    int n = nums.size();
    vector<int> dp(n  , 0);

    dp[0] = nums[0];
    for(int i = 1;i < n;i++)
    {
        int inclu = dp[i - 2] + nums[i];
        int exclu = dp[i - 1];
        dp[i] = max(inclu , exclu);
    }
    return dp[n - 1];
}
int solveOpt(vector<int> & nums)
{
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i = 1;i < n;i++)
    {
        int inclu = prev2 + nums[i];
        int exclu = prev1;
        int ans  = max(inclu , exclu);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int MaximumSumOfNonAdjacentEle(vector<int> & nums)
{
    // int n = nums.size();
    // int ans = solve(nums , n - 1);
    // return ans;

    int n = nums.size();
    vector<int> dp(n  , -1);
    int ans = solveMem(nums , n - 1 , dp);
    return ans;
}
int main (){
    return 0;
}  
