int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int area(int r, int c, vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    
    if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0;
    
    if(grid[r][c] == 1)
    {
        grid[r][c] = 0;
        int res = 1;
        for(int i = 0; i < 4; i++)
            res += area(r + dr[i], c + dc[i], grid);
        return res;
    }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int maxArea = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
            maxArea = max(maxArea, area(i, j, grid));
    }
    return maxArea;
}