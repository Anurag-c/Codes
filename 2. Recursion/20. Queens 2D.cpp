#include<bits/stdc++.h>
using namespace std;

// 1. 2D combinations
int placeQueens_2DC(int idx, int queens, vector<vector<int>>& matrix)
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
        
        matrix[row][col] = 1;
        c += placeQueens_2DC(i + 1, queens - 1, matrix);
        matrix[row][col] = 0;
    }
    return c;
}

// 2. 2D Permutations
int placeQueens_2DP(int queens, vector<vector<int>>& matrix)
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
    for(int i = 0 ; i < n * m ; i++)
    {
        int row = i / m;
        int col = i % m;
        
        if(matrix[row][col] != 1)
        {
            matrix[row][col] = 1;
            c += placeQueens_2DP(queens - 1, matrix);
            matrix[row][col] = 0;
        }
    }
    return c;
}

int main()
{
    vector<vector<int>>matrix(2, vector<int>(2,0));
    cout<<placeQueens_2DC(0, 2, matrix)<<"\n";
    cout<<placeQueens_2DP(2, matrix);
}