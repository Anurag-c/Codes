
void display(vector<vector<char>>& board)
{
    for(vector<char>& arr : board)
    {
        for(char ch : arr) cout<<ch<<" ";
        cout<<"\n";
    }
}

bool isSafe(int idx, int num, vector<vector<char>>& board)
{
    int n = board.size();
    int m = board[0].size();
    int row = idx / m;
    int col = idx % m;

    for(int i = 0; i < m ; i++)
    {
        if(board[row][i] - '0' == num) return false;
    }
    for(int i = 0; i < n; i++)
    {
        if(board[i][col] - '0' == num) return false;
    }

    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for(int i = 0; i < 3 ; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[row + i][col + j] - '0' == num) return false;
        }
    }
    return true;
}

bool solve(vector<int>& loc, vector<vector<char>>& board, int idx)
{
    if(idx == loc.size()) return true;
    
    int m = board[0].size();
    int row = loc[idx] / m;
    int col = loc[idx] % m;

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(loc[idx], num, board))
        {
            board[row][col] = '0' + num;
            if(solve(loc, board, idx + 1)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) 
{
    vector<int>loc;
    int n = board.size();
    int m = board[0].size();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(board[i][j] == '.') loc.push_back( (i * m) + j );
        }
    }
    solve(loc, board, 0);
}

// bitMasking
vector<int>row;
vector<int>col;
vector<int>mat;

void toggle(int r, int c, int num)
{
    int mask = (1 << num);
    row[r] ^= mask;
    col[c] ^= mask;
    mat[((r/3) * 3) + (c/3)] ^= mask;
}

bool solve(vector<int>& loc, vector<vector<char>>& board, int idx)
{
    if(idx == loc.size()) return true;
    
    int m = board[0].size();
    int r = loc[idx] / m;
    int c = loc[idx] % m;

    for(int num = 1; num <= 9; num++)
    {
        int mask = (1 << num);
        if( !(row[r] & mask) && !(col[c] & mask) && !(mat[((r/3) * 3) + (c/3)] & mask) )
        {
            toggle(r, c, num);
            board[r][c] = '0' + num;
            if(solve(loc, board, idx + 1)) return true;
            board[r][c] = '.';
            toggle(r, c, num);
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) 
{
    row.resize(9,0);
    col.resize(9,0);
    mat.resize(9,0);
    vector<int>loc;
    int n = board.size();
    int m = board[0].size();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(board[i][j] == '.') loc.push_back( (i * m) + j );
            else
            {
                int mask = (1 << (board[i][j] - '0'));
                row[i] |= mask;
                col[j] |= mask;
                mat[((i/3) * 3) + (j/3)] |= mask;
            }
        }
    }
    solve(loc, board, 0);
}