// https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps/0#
#include <bits/stdc++.h>
using namespace std;

bool printMazePaths(vector<vector<int>>& matrix, int sr, int sc, int n, vector<vector<int>>& ans)
{
    if(sr == n && sc == n) 
    {
        ans[sr][sc] = 1;
        return true;
    }
    
    ans[sr][sc] = 1;
    bool path_found = false;
    
    for(int i = 1 ; i <= matrix[sr][sc]; i++)
    {
        int new_c = sc + i;
        int new_r = sr + i;
        
        if(new_c > n && new_r > n) 
        {
            ans[sr][sc] = 0;
            return false;
        }
        
        if(new_c <= n) path_found = printMazePaths(matrix, sr, new_c, n, ans);
        if(path_found) return true;
        if(new_r <= n) path_found = printMazePaths(matrix, new_r, sc, n, ans);
        if(path_found) return true;
    }
    ans[sr][sc] = 0;
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>matrix(n,vector<int>(n));
        vector<vector<int>>ans(n,vector<int>(n,0));
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) cin>>matrix[i][j];
        
        bool path_found = printMazePaths(matrix, 0, 0, n - 1, ans);
        if(!path_found) cout<<"-1\n";
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < n ; j++) cout<<ans[i][j]<<" ";
                cout<<"\n";
            }
        }
    }
}