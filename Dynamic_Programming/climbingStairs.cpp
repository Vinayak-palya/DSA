#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
int solve(long long nStairs ,int i)
{
    if(i == nStairs)
    {
        return 1;
    }
    if(i > nStairs) return 0;
    return (solve(nStairs , i + 1) + solve(nStairs , i + 2)) %MOD;
}
int countDistinctWays(long long nStairs)
{
    int ans = solve(nStairs , 0);
    return ans;
}
int main (){
    return 0;
}