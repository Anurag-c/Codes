#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v, e;
    list<int>* adj;

    public:
    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        adj = new list<int>[v];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool hamil(int src, int totalVertices, int osrc, vector<bool>& vis)
    {
        if(totalVertices == 1)
        {
            for(int v : adj[src])
                if(v == osrc) return false;
            return true;
        }

        vis[src] = true;
        for(int v : adj[src])
        {
            if(!vis[v] && hamil(v, totalVertices - 1, osrc, vis))
            {
                vis[src] = false;
                return true;
            }
        }
        vis[src] = false;
        return false;
    }
};

void solve()
{
    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    for(int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u - 1,v - 1);
    }
    vector<bool>vis(v, false);
    for(int i = 0 ;i < v; i++)
    {
        if(g.hamil(i,v,i,vis)) 
        {
            cout<<"1\n";
            return;
        }
    }
    cout<<"0\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}

