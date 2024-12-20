#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
void dfs(int node , unordered_map<int , list<int> > &adj ,unoredered_map<int , bool> &vis , stack<int> &st)
{
    vis[node] = true;
    for(auto nbr: adj[node])
    {
        if(!vis[nbr]){
            dfs(nbr , adj , vis , st);
        }
    }
    st.push(node);
}
void revDfs(int node , unordered_map<int , bool > & vis,unordered_map<int , list< int>  > &adj)
{
    vis[node] = true;
    for(auto nbr : adj[node])
    {
        if(!vis[nbr])
        {
            revDfs(nbr , vis , adj);
        }
    }
    return ;
}
int scc(int v , vector<vector<int> > edges)
{
    // create adj list
    unordered_map<int, list<int> > adj;
    for(int i = 0;i < edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    stack<int> st;
    unordered_map<int , bool> visited;

    for(int i = 0;i < v;i++)
    {
        if(!visited[i])
        {
            dfs(i , adj , visited , st);
        }
    }
    // create a transpose graph
    unordered_map<int , list<int> > transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for(auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    // dfs calling using above ordering
    int count = 0;
    while(!st.empty())
    {
        int top = st.top();
        st.pop();
        if(!visited[top])
        {
            count++;
            revDfs(top , visited ,transpose);
        }


    }
    return count;
    
}
int main()
{
    return 0;
}