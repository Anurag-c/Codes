
vector<int>row;
vector<int>col;
vector<int>mat;

bool isValidSudoku(vector<vector<char>>& board) 
{
    row.resize(9,0);
    col.resize(9,0);
    mat.resize(9,0);
    int n = board.size();
    int m = board[0].size();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(board[i][j] == '.') continue;
            
            int mask = (1 << (board[i][j] - '0'));
            if( !(row[i] & mask) && !(col[j] & mask) && !(mat[((i/3) * 3) + (j/3)] & mask) )
            {
                row[i] |= mask;
                col[j] |= mask;
                mat[((i/3) * 3) + (j/3)] |= mask;
            }
            else return false;
        }
    }
    return true;
}