// shortest distance 
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
int bellManFord(int n , int m , int src , int dest , vector<vector<int> > &edges)
{
    vector<int> dist(n+1 , 1e9);
    dist[src] = 0;

    for(int i  = 1;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != 1e9 and (dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }

    }
    //  check for negative cycles
    bool flag = 0;
    for(int j = 0;j < m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u] != 1e9 and (dist[u] + w < dist[v]))
            {
                flag = 1;
            }
        }
        if(!flag)
        {
            return dist[dest];
        }
    return -1;
}
int main (){
    return 0;
}               