int singleJump_Memo(int r, int c, int m, int n, vector<vector<int>>& dp)
{
    if(r == m - 1 && c == n - 1) return dp[r][c] = 1;
    if(dp[r][c] != -1) return dp[r][c]

    int ans = 0;
    
    if(c + 1 < n)
        ans += singleJump_Memo(r, c + 1, m, n, dp);
    if(r + 1 < m && c + 1 < n)
        ans += singleJump_Memo(r + 1, c + 1, m, n, dp);
    if(r + 1 < m)
        ans += singleJump_Memo(r + 1, c, m, n, dp);

    return dp[r][c] = ans;
}

long long singleJump_Tab(int m, int n)
{
    vector<vector<long long>>dp(m,vector<long long>(n, 0));

    for(int r = m - 1; r >= 0; r--)
    {
        for(int c = n - 1; c >= 0; c--)
        {
            if(r == m - 1 && c == n - 1) 
            {
                dp[r][c] = 1;
                continue;
            }   
            if(c + 1 < n)
                dp[r][c] = (dp[r][c] % M + dp[r][c + 1] % M) % M;
            if(r + 1 < m && c + 1 < n)
                dp[r][c] = (dp[r][c] % M + dp[r + 1][c + 1] % M) % M;
            if(r + 1 < m)
                dp[r][c] = (dp[r][c] % M + dp[r + 1][c] % M) % M;
        }
    }
    return dp[0][0];
}

// p and c for only right and down



