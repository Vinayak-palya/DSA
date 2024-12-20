#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;
// BFS traversal
bool detectCycle(unordered_map<int , set<int> >& adj , unordered_map<int , bool> &visited , int src)
{
    unordered_map<int , int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int front  = q.front();
        q.pop();
        for(auto neighbour : adj[front])
        {
            if(visited[neighbour] && neighbour != parent[front])
            {
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
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
// DFS Traversal
bool detectCycleDFS(int node , int parent , unordered_map<int , set<int> >& adj , unordered_map<int , bool> &visited )
{
    visited[node] = true;
    // base case

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = detectCycleDFS(neighbour , node , adj , visited);
            if(cycleDetected)
            {
                return true;
            }
            else if(neighbour != parent)
            {
                // cycle detection
                
                return true;
            }
        }
    }
    return false;
}
string cycleDetectionDFS(vector<vector<int> > &edges , int n , int m)
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
            bool ans = detectCycleDFS(i , -1 , adj , visited);
            if(ans == 1)
            {
                return "YES";
            }
        }
    }
    return "NO";
    
}
int main (){

    return 0;
}