vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
{
    list<int>* adj = new list<int>[n];
    vector<int>ans;
    vector<int>indegree(n, 0);
    queue<int>q;
    
    for(vector<int>e : prerequisites)
    {
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
        
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        
        for(int v : adj[u])
            if(--indegree[v] == 0)
                q.push(v);
    }
    
    reverse(ans.begin(), ans.end());
    if(ans.size() == n) return ans;
    return {};
}