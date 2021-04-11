vector<int>dr = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int>dc = {0, 1, 1, 1, 0, -1, -1, -1};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    if(grid.size() == 0 || grid[0].size() == 0 || grid[0][0]) return -1;
    
    int m = grid.size();
    int n = grid[0].size();
    if(grid[m - 1][n - 1] == 1) return -1;
    if(m - 1 == 0 && n - 1 == 0) return 1;
    
    queue<pair<int, int>>q;
    q.push({0,0});
    grid[0][0] = 1;
    
    int level = 0;
    while(!q.empty())
    {
        level++;
        int size = q.size();
        while(size--)
        {
            pair<int, int>p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if(r == m - 1 && c == n - 1) return level;
            for(int i = 0 ; i < 8; i++)
            {
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] == 0)
                {
                    grid[new_r][new_c] = 1;
                    q.push({new_r, new_c});
                }
            }
        }
    }
    return -1;
}