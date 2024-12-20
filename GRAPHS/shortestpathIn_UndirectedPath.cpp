#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

vector<int> shortestPath(vector<pair<int , int> > edges , int e , int v , int src , int des)
{
    // create adjacency list
    unordered_map<int , list<int> > adj;
    for(int i = 0;i < e;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int , int > parent;
    unordered_map<int , bool > visited;
    queue<int > q;
    q.push(src);
    parent[src] = -1;
    visited[src] = true;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto i: adj[front])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
        }
    }
    vector<int> ans;
    int currNode = des;
    ans.push_back(des);
   while (currNode != src)
   {
    currNode = parent[currNode];
    ans.push_back(currNode);
   }
   reverse(ans.begin() , ans.end());
   return ans;
   
    
}
int main ()
{
    return 0;
}