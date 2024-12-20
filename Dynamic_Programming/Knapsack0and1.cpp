#include<iostream>
#include<vector>
using namespace std;

// recursive solution
int solve(vector<int> &weights , vector<int> &values , int index, int capacity)
{
    //  Base case
    // if only one item to steal then directly compare with its knapsack value
    if(index == 0)
    {
        if(weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    
    if(weights[index] <= capacity)
    {
        include = values[index] + solve(weights , values , index - 1 , capacity - weights[index]);
    }
    
    int exclude = solve(weights , values , index - 1 , capacity);

    int ans = max(include , exclude);
    return ans;
}


// recursion  + memoization

int solveMem(vector<int> &weights , vector<int> &values , int index, int capacity , vector<vector<int> > &dp)
{
    //  Base case
    // if only one item to steal then directly compare with its knapsack value
    if(index == 0)
    {
        if(weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    if(dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    int include = 0;
    
    if(weights[index] <= capacity)
    {
        include = values[index] + solveMem(weights , values , index - 1 , capacity - weights[index] , dp);
    }
    
    int exclude = solveMem(weights , values , index - 1 , capacity , dp);

    dp[index][capacity] = max(include , exclude);
    return dp[index][capacity];
}

// tabulation method
int solveTab(vector<int> &weights , vector<int> &values , int n, int capacity )
{


    // step1;
    vector<vector<int> > dp(n  , vector<int> (capacity  +1, 0));

    // step2: Analyze base case
    for(int index = weights[0];index <= capacity;index++)
    {
        if(weights[0] <= capacity)
        {
            dp[0][index] = values[0];

        }
        else{
            dp[0][index] = 0;
        }
    }

    for(int index = 1;index < n;index++)
    {
        for(int w = 0;w < capacity+1;w++)
        {
            int include = 0;
            if(weights[index] <= w)
            {
                include = values[index] + dp[index - 1][w - weights[index]];
            }
            int exclude = dp[index - 1][w];
            dp[index][w] = max(exclude , include);
        }
    }
    return dp[n -1][capacity];
}

// space optimized
int solveOpt(vector<int> &weights , vector<int> &values , int n, int capacity )
{
    vector<int> prev(capacity + 1 , 0);
    vector<int> curr(capacity +1 , 0);
    for(int index = weights[0];index<= capacity;index ++)
    {
        if(weights[0] <= capacity)
        {
            prev[index] = values[0];

        }
        else{
            prev[index] = 0;
        }
    }

    for(int index = 1;index < n;index++)
    {
        for(int w = 0;w < capacity+1;w++)
        {
            int include = 0;
            if(weights[index] <= w)
            {
                include = values[index] + prev[w - weights[index]];
            }
            int exclude = prev[w];
            curr[w] = max(exclude , include);
        }
        prev = curr;
    }
    return prev[capacity];
}

int MostOpt(vector<int> &weights , vector<int> &values , int n, int capacity )
{
    
    vector<int> curr(capacity +1 , 0);
    for(int index = weights[0];index<= capacity;index ++)
    {
        if(weights[0] <= capacity)
        {
            curr[index] = values[0];

        }
        else{
            curr[index] = 0;
        }
    }

    for(int index = 1;index < n;index++)
    {
        for(int w = capacity;w >= 0;w--)
        {
            int include = 0;
            if(weights[index] <= w)
            {
                include = values[index] + curr[w - weights[index]];
            }
            int exclude = curr[w];
            curr[w] = max(exclude , include);
        }
        
    }
    return curr[capacity];
}

int knapSack(vector<int> weights , vector<int> values , int n, int maxWeights)
{
    vector<vector<int> > dp(n ,vector<int> (maxWeights +1 , -1));
    // return solve(weights , values , n - 1, maxWeights);
    return solveMem(weights , values , n -1 , maxWeights , dp);
}
int main (){
    return 0;
}