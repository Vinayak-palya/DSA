#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<set>
using namespace std;
void ADJList(unordered_map<int  , set <int> > &adj , vector<pair <int  , int> >&edges){
    for(int i = 0;i < edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);

    }

}
void bfs(unordered_map<int  , set<int > > &adj , vector<int> &ans ,int node , unordered_map< int , bool > &visited){
    visited[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}
vector<int> BFS(int vertex , vector<pair <int , int> > &edges){
    unordered_map<int , set<int> > adj;
    vector<int> ans;
    unordered_map< int , bool > visited(v);
    ADJList(adj , edges);

    //traverse all component of graphs
    for(int i = 0;i < vertex;i++){
        if(!visited[i]){
            bfs(adj , ans , i , visited);
        }
    }
    return ans;
}
int main (){

    return 0;
}