int time(vector<vector<int>>& adj, vector<int>& informTime, int head)
{
    int ans = 0;
    for(int i = 0 ; i < adj[head].size(); i++)
        ans = max(ans, time(adj, informTime, adj[head][i]));
    
    return ans + informTime[head];
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{
    vector<vector<int>>adj(n);
    for(int i = 0 ; i < n; i++)
        if(i != headID) 
            adj[manager[i]].push_back(i);
    
    return time(adj, informTime, headID);
}