bool solve(int r, int c, vector<vector<char>>& board, string word)
{   
    bool res = false;
    if(word[0] == board[r][c])
    {
        if(word.length() == 1) return true;
        board[r][c] = '.';
        if(r + 1 < board.size() && board[r + 1][c] != '.') res = res || solve(r + 1, c, board, word.substr(1));
        if(r - 1 >= 0 && board[r - 1][c] != '.') res = res || solve(r - 1, c, board, word.substr(1)); 
        if(c + 1 < board[0].size() && board[r][c + 1] != '.') res = res || solve(r, c + 1, board, word.substr(1));
        if(c - 1 >= 0 && board[r][c - 1] != '.') res = res || solve(r, c - 1, board, word.substr(1));
        board[r][c] = word[0];
    }
    return res;
}


bool exist(vector<vector<char>>& board, string word) 
{
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(word[0] == board[i][j])
                if(solve(i, j, board, word)) return true;
        }
    }
    return false;
}