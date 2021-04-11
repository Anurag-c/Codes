bool isCycle(list<int>* adj, vector<int>& vis, int u)
{
    vis[u] = 1;
    for(int v : adj[u])
    {
        if(vis[v] == -1)
        {
            bool cycle_found = isCycle(adj, vis, v);
            if(cycle_found) return true;
        }
        else if(vis[v] == 1) return true;
    }
    vis[u] = 0;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    list<int>*adj = new list<int>[numCourses];
    vector<int>vis(numCourses, -1);
    
    for(vector<int>e : prerequisites)
        adj[e[0]].push_back(e[1]);
    
    for(int i = 0; i < numCourses; i++)
    {
        if(vis[i] == -1)
        {
            bool cycle_found = isCycle(adj, vis, i);
            if(cycle_found) return false;
        }
    }
    return true;
}
