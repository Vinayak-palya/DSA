#include<iostream>
#include<vector>
using namespace std;
int solve(int i , int j , vector<vector<int> > &mat , int & maxi)
{
    if(i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    int right = solve(i , j+ 1 , mat , maxi);
    int dia = solve(i + 1 , j +1 ,mat , maxi);
    int down = solve(i + 1 , j , mat , maxi);
    if(mat[i][j] == 1)
    {
        int ans = 1 + min(right , min(dia, down));
        maxi = max(ans , maxi);
        return maxi;
    }
    return 0;
}
int solveMem(int i , int j , vector<vector<int> > &mat , int & maxi , vector<vector<int> > & dp)
{
    if(i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solve(i , j+ 1 , mat , maxi ,dp);
    int dia = solve(i + 1 , j +1 ,mat , maxi ,dp);
    int down = solve(i + 1 , j , mat , maxi ,dp);
    if(mat[i][j] == 1)
    {
        int ans = 1 + min(right , min(dia, down));
        maxi = max(ans , dp[i][j]);
        return dp[i][j];
    }
    return 0;
}

int solveTab(int i , int j , vector<vector<int> > &mat , int & maxi )
{
    
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int> > dp(n +1 , vector<int> (m +1 , 0));
    
    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = m -1;j >= 0;j--)
        {

            int right = dp[i][j + 1];
            int dia = dp[i + 1][j + 1];
            int down = dp[i +1][j];

            if(mat[i][j] == 1)
            {
                int ans = 1 + min(right , min(dia, down));
                maxi = max(ans , dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
    
    
    
}
int solveOpt(vector<vector<int> > &mat , int & maxi)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<int> curr(col+ 1 , 0);
    vector<int> next(col+ 1 , 0);


    for(int i = n - 1;i >= 0;i--)
    {
        for(int j = m -1;j >= 0;j--)
        {

            int right = curr[j + 1];
            int dia = next[j + 1];
            int down = next[j];

            if(mat[i][j] == 1)
            {
                int ans = 1 + min(right , min(dia, down));
                maxi = max(ans , curr[j]);
            }
            else{
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return next[0];
}

int maxSquare(int n , int m , vector<vector<int> > mat)
{
    vector<vector<int> > dp(n , vector<int>(m , -1));
    int maxi = 0;
    int ans = solveOpt( mat , maxi);

    return maxi;
}
int main (){
    return 0;
}