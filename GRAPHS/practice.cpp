// kahn's algo
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<set>
using namespace std;
bool detectcycle(unordered_map< int , set<int> > adj, unordered_map<int , bool> visited , int src)
{
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int front = q.front;
        for(auto i: adj[front])
        {
            if(!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
            else if(parent[i] != front)
            {
                return  true;
            }
        }
    }
    return false;
    
}
string cycleDetection(vector<vector<int> > &edges , int n , int m)
{
    unordered_map<int , set<int> > adj;
    for(int i = 0;i < m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }
    unordered_map<int , bool> visited;
    for(int i = 0;i < n;i++){
        if(!visited[i])
        {
            bool ans = detectCycle(adj , visited , i);
            if(ans == 1)
            {
                return "YES";
            }
        }
    }
    return "NO";
    
}
int main ()
{
    return  0;
}