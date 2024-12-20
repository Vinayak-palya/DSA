#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;
void dfs(int node , int parent ,int &time , vector<int> &disc , vector<int> &low , 
    vector<vector<int> > &result , unordered_map<int , list<int> > &adj , unordered_map<int ,bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = time++;
    for(auto nbr : adj[node])
    {
        if(nbr == parent)
        {
            continue;
        }
        if(!vis[nbr])
        {
            dfs(nbr , node ,  time , disc , low , result , adj , vis);
            low[node] = min(low[node] , low[nbr]);
            // check edge is bridge or not
            if(low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            // backedge
            low[node] = min(low[node] , disc[nbr]);
        }
    }

}
vector<vector<int> > findBridges(vector<vector<int> > &edges  , int v , int e)
{
    unordered_map<int , list<int> > adj;
    for(int i = 0;i < e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int ,bool> vis;
    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    vector<vector<int> > result;
    // dfs
    for (int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i , parent ,  timer , disc , low , result , adj , vis);
        }

    }
    return result ;

}
int main (){
    return 0;
}                           