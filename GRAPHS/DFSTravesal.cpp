#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
void dfs(int node , unordered_map<int , set<int> > &adj , unordered_map< int , bool > &visited , vector<int> &component)
{
    // ans store
    component.push_back(node);
    // mark visited
    visited[node] = true;
    // hr connected node ke liye recursive call
    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i , adj , visited , component);
        }
    }
}
vector<vector<int> > DFSTraversal(int v , int e , vector<pair<int , int > > &edges)
{
    // prepare adj list
    unordered_map<int, set<int> > adj;
    for(int i = 0;i < edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);

    }
    vector<vector<int> > ans;
    unordered_map<int  , bool > visited(v);
    for(int i = 0;i < v;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i , adj , visited , component);
            ans.push_back(component);
        }
    }
    return ans;

}
int main (){

    return 0;
}