#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;

bool cycledetection(int v , int e , vector<vector<int> > &edges)
{
    unordered_map<int , set<int> > adj;
    for(int i = 0;i < e;i++)
    {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;

        adj[u].insert(v);
    }
    vector<int> indegree(v);
    for(auto i : adj)
    {
        for(auto i: i.second)
        {
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i = 0;i < v;i++)
    {
        if(inserted[i] == 0)
        {
            q.push(i);
        }

    }
    
    int cnt = 0;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++;
        for(auto i : adj[front])
        {
            indegree[i]--;
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

    }
    if(cnt == v)
    {
        return false;
    }
    return true;
}
int main ()
{
    return 0;
}