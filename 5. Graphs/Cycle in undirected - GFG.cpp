
// CYCLE TYPE BFS
bool bfs(int src, vector<int>* adj, vector<bool>& visited)
{
    queue<int>q;
    q.push(src);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(visited[u])
            return true;

        visited[u] = true;
        for(int v : adj[u])
        {
            if(!visited[v]) 
                q.push(v);
        }
    }
    return false;
}

bool isCycle(int V, vector<int>* adj)
{
    vector<bool>visited(V, false);
    
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && bfs(i, adj, visited)) // check all connected components
            return true; 
    }
    return false;
}

// BFS and Parent array --> SHORTEST PATH TYPE BFS
bool bfs(int src, vector<int>* adj, vector<bool>& visited, vector<int>& parent)
{
    queue<int>q;
    q.push(src);
    visited[src] = true;
    
    while(!q.empty())
    {
       int u = q.front();
       q.pop();
       
       for(int v : adj[u])
       {
           if(!visited[v])
           {
               parent[v] = u;
               q.push(v);
               visited[v] = true;
           }
           else if(v != parent[u])
                return true;
       }
    }
    return false;
}

bool isCycle(int V, vector<int>* adj)
{
    vector<bool>visited(V, false);
    vector<int>parent(V, -1);
    
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && bfs(i, adj, visited, parent)) 
            return true; 
    }
    return false;
}

// Using DFS
bool cycle_found(int u, int parent, vector<int>* adj, vector<bool>& visited)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(v != parent && visited[v]) 
            return true;
        
        if(!visited[v] && cycle_found(v, u, adj, visited))
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int>* adj)
{
    vector<bool>visited(V, false);
    
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && cycle_found(i, -1, adj, visited)) 
            return true; 
    }
    return false;
}