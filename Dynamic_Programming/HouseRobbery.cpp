#include<iostream>
#include<vector>
using namespace std;

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
long long int houseRobbery(vector<int> & valueInHouse)
{
    int n = valueInHouse.size();
    if( n == 1)
    {
        return valueInHouse[0];
    }
    vector<int> first , second;
    for(int i = 0;i< n;i++)
    {
        if(i != n -1)
        {
            first.push_back(valueInHouse[i]);
        }
        if(i != 0)
        {
            second.push_back(valueInHouse[i]);
        }

    }
    return max(solveOpt(first)  , solveOpt(second));
}
int main (){
    return 0;
}  
