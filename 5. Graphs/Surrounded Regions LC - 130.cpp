int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, vector<vector<char>>& board)
{
    int m = board.size();
    int n = board[0].size();
    
    board[r][c] = '#';
    for(int i = 0; i < 4; i++)
    {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && board[new_r][new_c] == 'O')
            dfs(new_r, new_c, board);
    }
}

void solve(vector<vector<char>>& board) 
{
    int m = board.size();
    int n = board[0].size();
    
    for(int i = 0; i < m; i++)
    {
        if(board[i][0] == 'O') dfs(i, 0, board); 
        if(board[i][n - 1] == 'O') dfs(i, n - 1, board);
    }
    
    for(int j = 0; j < n; j++)
    {
        if(board[0][j] == 'O') dfs(0, j, board);
        if(board[m - 1][j] == 'O') dfs(m - 1, j, board);
    }
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if(board[i][j] == '#') board[i][j] = 'O';
        }
    }
}