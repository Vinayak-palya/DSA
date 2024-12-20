#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
vector<int> dijkstras(vector<vector<int> > edges , int e , int v , int src)
{
    unordered_map<int , list<pair<int, int> > > adj;
    for(int i = 0;i < e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v , w));
        adj[v].push_back(make_pair(u , w));


    }
    set<pair<int ,int> > st;
    vector<int> dist(v , INT_MAX);
    dist[src] = 0;
    st.insert(make_pair(dist[src] , src));
    while(!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());
        for(auto neighbour : adj[topNode])
        {
            if(nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first));
                // if record find then erase it
                if(record != st.end())
                {
                    st.erase(record);
                }

            }
            dist[neighbour.first] = nodeDistance + neighbour.second;

            st.insert(make_pair(dist[neighbour.first] , neighbour.first));
        }
        

    }
    return dist;
}
int main ()
{
    return 0;
}