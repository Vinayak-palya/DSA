#include<iostream>
#include<vector>
#include<unordered_map>
#include<vector>
#include<set>
#include<stack>
using namespace std;
void toposort(int node , unordered_map<int , set<int> > &adj , 
vector<bool >  &visited , stack<int> &s)
{
    visited[node] = 1;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            toposort(neighbour , adj , visited , s);
        }
    }
    // imp
    s.push(node);
}
vector<int> topoLogicalSort(vector<vector<int> > & edges , int v , int e)
{
    // creating adj list
    unordered_map<int , set<int> > adj;
    for(int i = 0;i < e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
    }
    // call dfstopologicalsort
    vector< bool >  visited(v);
    stack<int> s;
    for(int i = 0;i < v;i++)
    {
        if(!visited[i])
        {
            toposort(i , adj , visited , s);
        }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
}
int main ()
{
    return 0;
}