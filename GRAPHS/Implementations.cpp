#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T , list<T> > adj;
    void addEdge(T u , T v , bool direction){
        // if direction == 1 --> directed
        // if direction == 0 --> undirected graph

        // create an edge from u to v
        adj[u].push_back(v);
        if(direction != 1)
        {
            adj[v].push_back(u);
        }
        return;
    }
    void printAdjList(){
        for(auto i : adj){
            cout << i.first << "-> ";
            for(auto j : i.second){
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};
int main(){
    int n;
    cout << "Enter no. of Nodes : " << endl;
    cin >> n;
    int m;
    cout << "Enter No. of Edges : " << endl;
    cin >> m;

    Graph<int> g;
    for(int i = 0;i < m;i++){
        int u , v;
        cin >> u >> v;
        // create an undirtected graph
        g.addEdge(u , v ,0);


    }
    // printing graph
    g.printAdjList();
    return 0;
}