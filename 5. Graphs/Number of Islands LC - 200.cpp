int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void dfs(int r, int c, vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    
    if(r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == '1')
    {
        grid[r][c] = '0';
        for(int i = 0; i < 4; i++) 
            dfs(r + dr[i], c + dc[i], grid);
    }
}
int numIslands(vector<vector<char>>& grid) 
{
    int islands = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == '1') 
            {
                islands++;
                dfs(i, j, grid);
            }
        }
    }
    return islands;
}

