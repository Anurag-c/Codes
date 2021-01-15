#include<bits/stdc++.h>
using namespace std;

int N_queens(int idx, int queens, vector<vector<int>>& matrix, vector<bool>& vis_r, vector<bool>& vis_c, vector<bool>& diag, vector<bool>& adiag)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    if(queens == 0)
    {
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < m ; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";   
        return 1;
    }
    
    int c = 0;
    for(int i = idx ; i < n * m ; i++)
    {
        int row = i / m;
        int col = i % m;
        if(!vis_r[row] && !vis_c[col] && !diag[row - col + m - 1] && !adiag[row + col])
        {
            matrix[row][col] = 1;
            adiag[row + col] = diag[row - col + m - 1] = vis_r[row] = vis_c[col] = true;
            c += N_queens(i + 1, queens - 1, matrix, vis_r, vis_c, diag, adiag);
            matrix[row][col] = 0;
            adiag[row + col] = diag[row - col + m - 1] = vis_r[row] = vis_c[col] = false;
        }
    }
    return c;
}

int main()
{
    vector<vector<int>>matrix(4, vector<int>(4,0));
    vector<bool>vis_r(4, false);
    vector<bool>vis_c(4, false);
    vector<bool>diag(7, false); 
    vector<bool>adiag(7, false);
    cout<<N_queens(0, 4, matrix, vis_r, vis_c, diag, adiag)<<"\n";
}


