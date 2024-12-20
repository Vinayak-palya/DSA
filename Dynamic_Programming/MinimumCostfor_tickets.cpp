#include<iostream>
#include<vector>
using namespace std;
int solve(int n , vector<int>& days , vector<int>& cost , int &index)
{
    // base case
    if(index >= n)
    {
        return 0;
    }

    // 1 day pass
    int option1 = solve(n , days , cost , index +1);
    int i;
    // 7 day pass
    for(i = index;i < n && days[i] < days[index] + 7;i++);
    
    int option2 = cost[1] + solve(n , days , cost , i);

    // 30 days
    for(i = index;i < n && days[i] < days[index] + 30;i++);
    
    int option3 = cost[2] + solve(n , days , cost , i);

    return min(option1 , min(option2 , option3));

}
int solveMem(int n , vector<int>& days ,int &index , vector<int>& cost , int dp){
    // base case
    if(index >= n)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }

    // 1 day pass
    int option1 = solve(n , days , cost , index +1);
    int i;
    // 7 day pass
    for(i = index;i < n && days[i] < days[index] + 7;i++);
    
    int option2 = cost[1] + solve(n , days , cost , i);

    // 30 days
    for(i = index;i < n && days[i] < days[index] + 30;i++);
    
    int option3 = cost[2] + solve(n , days , cost , i);

    dp[index] = min(option1 , min(option2 ,option3));

    return dp[index];
}

int solveTab(int n , vector<int>& days , vector<int>& cost , int &index)
{
    vector<int> &dp(n + 1 , INT_MAX);
    dp[n] = 0;
    for(int k = n -1;k >= 0;k--)
    {
    // 1 day pass
    int option1 = dp[k + 1];
    int i;
    // 7 day pass
    for(i = k;i < n && days[i] < days[k] + 7;i++);
    
    int option2 = cost[1] + dp[i];

    // 30 days
    for(i = k;i < n && days[i] < days[k] + 30;i++);
    
    int option3 = cost[2] + dp[i];
    }
    return dp[0];
}
int find(int n , vector<int> days , vector<int> cost)
{
    vector<int> dp(n + 1 , -1);
}
int main (){
    return 0;
}