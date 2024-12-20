#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
vector<int> KahnsAlgo(vector<vector<int> > &edges , int v , int e)
{
    // create adjlist
    unordered_map<int  , set<int> > adj;
    for(int i=0;i < e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
    }
    // find al indegrees
    vector<int> indegree(v);
    for(auto i : adj)
   {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
   }
   queue<int> q;
   for(int i = 0;i < v;i++)
   {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
   }
   vector<int> ans;
    //    do bfs
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
int main (){
    return 0;
}