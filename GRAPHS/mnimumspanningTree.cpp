#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<unordered_map>
using namespace std;
vector<pair<pair<int , int> , int> > calculateMSTprimsAlgo(int n , int m, vector<pair<pair<int , int> , int> > edges)
{
    unordered_map<int , list<pair<int , int> > > adj;
    for(int i = 1;i <= edges.size();i++)  // always make sure that your nodes are staring from the 0 or 1
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;
        adj[u].push_back(make_pair(v ,w));
        adj[v].push_back(make_pair(u , w));
    }
    vector<int> key(n+1 ,INT_MAX);
    vector<bool> mst(n+1 , false);
    vector<int> parent(n+1 , -1);
    // let the souce node == one
    key[1] = 0;
    parent[1] = -1;
    mst[1] = true;
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // find u
        for(int j = 1;j <= n;j++)
        {
            if(mst[u] == false && key[j] < mini)
            {
                mini = key[u];
                u = j;
            }
            //  mark min node as true;
            mst[u] = true;
            // check its adjacent node
            for(auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if(mst[v] == false && w < key[v])
                {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
    }
    vector<pair<pair<int , int> , int > > result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair(make_pair( i , parent[i]) , key[i]));
        // result.push_back({{ i , parent[i]} , key[i]});
    }
    
    return result;

}
int main (){
    return 0;
}   