// USING CYCLE TYPE BFS
bool bipartite(int src, vector<vector<int>>& adj, vector<int>& color)
{
    queue<int>q;
    q.push(src);
    bool isCycle = false;
    int c = 0; // red

    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int u = q.front();
            q.pop();

            if(color[u] != -1)
            {
                isCycle = true;
                if(color[u] != c) 
                    return false;
                continue;
            }

            color[u] = c;
            for(int v : adj[u])
            {
                if(color[v] == -1)
                    q.push(v);
            }
        }
        c = c ^ 1;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& adj) 
{
    int V = adj.size();
    vector<int>color(V, -1);
    
    for(int i = 0; i < V; i++)
    {
        if(color[i] == -1)
        {
            bool check = bipartite(i, adj, color);
            if(!check) return false;
        }
    }
    return true;
}

//USING SHORTEST PATH TYPE BFS
bool bipartite(int src, vector<vector<int>>& adj, vector<int>& color)
{
    queue<int>q;
    q.push(src);
    color[src] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(color[v] == -1)
            {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
            else if(color[u] == color[v]) 
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& adj) 
{
    int V = adj.size();
    vector<int>color(V, -1);
    
    for(int i = 0; i < V; i++)
    {
        if(color[i] == -1)
        {
            bool check = bipartite(i, adj, color);
            if(!check) return false;
        }
    }
    return true;
}

// USING DFS
class Solution {

    bool bipartite(vector<vector<int>>& adj, vector<int>& color, int u, int c)
    {
        color[u] = c;
        for(int v : adj[u])
        {
            if(color[v] == -1)
            {
                bool check = bipartite(adj, color, v, c ^ 1);
                if(!check) return false;
            }
            else if(color[v] == color[u])
                return false;
        }
        return true;
    }
    
    public:
    
    bool isBipartite(vector<vector<int>>& adj) 
    {
        int V = adj.size();
        vector<int>color(V, -1);
        for(int i = 0; i < V; i++)
        {
            if(color[i] == -1)
            {
                bool check = bipartite(adj, color, i, 0);
                if(!check) return false;
            }
        }
        return true;
    }
};