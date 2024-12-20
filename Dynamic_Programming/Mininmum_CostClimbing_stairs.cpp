#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int> & cost , int n)
{
    // base case
    if(n == 0){
        return cost[0];
    }
    if(n == 1)
    {
        return cost[1];
    }
    int ans = min(solve(cost , n - 1) , solve(cost , n - 2)) + cost[n];
    return ans;
}
int solve3(vector<int> & cost , int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2;i < n;i++){
        dp[i] = cost[i] + min(dp[i - 1] , dp[i - 2]);
    }
    return min(dp[n - 1] , dp[n - 2]);
}
int solve4(vector<int> & cost , int n)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i=2;i < n;i++)
    {
        int curr = cost[i] + min(prev1  , prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return  min(prev1 , prev2);

}
int solve2(vector<int> & cost , int n , vector<int> & dp)
{
    if(n == 0)
    return cost[0];
    if(n == 1)
    return cost[1];
    // step[3]
    if(dp[n] != -1)
    return dp[n];
    // step2
    dp[n] = min(solve2(cost , n - 1 , dp) , solve2(cost , n - 2 , dp)) + cost[n];
    return dp[n];
}
int minCostClimbing(vector<int> & cost)
{
    // int n = cost.size();
    // int ans = min(solve(cost , n- 1) , solve(cost , n - 2));

    // solve 3
    // int n = cost.size();
    // vector<int> dp(n + 1 , -1);

    // int ans = min(solve2(cost , n- 1 , dp) , solve2(cost , n - 2 , dp));
    // return ans;

    // int n = cost.size();
    // return solve3(cost ,n);

    int n = cost.size();
    return solve4(cost  ,n);
    
}
int main (){
    return 0;
}