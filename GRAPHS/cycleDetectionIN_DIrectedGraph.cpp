#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
bool checkCycle(int  node , unordered_map<int , set<int> > &adj , unordered_map<int , 
    bool> &visited , unordered_map<int , bool> &dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = checkCycle(neighbour , adj , visited , dfsVisited);
            if(cycleDetected)
            {
                return true;
            }
        }
        else if(dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}
int detectCycleInDirectedgraph(int n , vector<pair<int , int> > & edges)
{
    unordered_map<int , set<int> > adj;
    for(int i = 0;i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
    }
    unordered_map<int , bool> visited;
    unordered_map<int , bool> dfsVisited;
    for(int i = 1;i <= n;i++)
    {
        if(!visited[i])
        {
            bool cycleFound = checkCycle(i , adj , visited , dfsVisited);
            if(cycleFound)
            {
                return true;
            }
        }
    }
    return false;
}
int main ()
{
    return 0;
}   