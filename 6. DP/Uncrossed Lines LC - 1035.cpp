int maxUncrossedLines(vector<int>& A, vector<int>& B) 
{
    int m = A.size();
    int n = B.size();
    
    vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            if(A[i] == B[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    
    return dp[0][0];
}