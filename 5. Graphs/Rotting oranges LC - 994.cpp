int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int rot(queue<int>& q, vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    int time = -1;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int r = u / m;
                int c = u % m;
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c] == 1)
                {
                    grid[new_r][new_c] = 2;
                    q.push(new_r * m + new_c);
                }
            }
        }
        time++;
    }
    return time;
}

int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    
    int t = 0;
    queue<int>q;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == 2)
                q.push(i * m + j);
    
    if(q.size() != 0) t = rot(q, grid);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == 1)
                return -1;
    
    return t;
}

