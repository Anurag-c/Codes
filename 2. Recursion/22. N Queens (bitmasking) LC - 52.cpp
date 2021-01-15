
int vis_c = 0;
int diag = 0;
int adiag = 0;

void toggle(int row, int col, int n)
{
    vis_c ^= (1<<col);
    diag ^= (1<<(row-col+n-1));
    adiag ^= (1<<(row+col));
}

int NQueens(int row, int queens, int n)
{
    if(queens == 0) return 1;
    
    int count = 0;
    for(int col = 0; col < n; col++)
    {
        if( !((vis_c>>col)&1) && !((diag>>(row-col+n-1))&1) && !((adiag>>(row+col))&1) )
        {
            toggle(row, col, n);
            count += NQueens(row + 1, queens - 1, n);
            toggle(row, col, n);
        }
    }
    return count;
}

int totalNQueens(int n) 
{
    return NQueens(0, n, n);
}