
// MEMO
int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
{
    if(i == s1.length() || j == s2.length())
        return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s1[i] == s2[j])
        return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1, dp);
    
    return dp[i][j] = max(solve(s1, s2, i + 1, j, dp), solve(s1, s2, i , j + 1, dp));
}
    
// Tabulation
int longestCommonSubsequence(string text1, string text2) 
{
    int n = text1.length();
    int m = text2.length();
    
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    
    for(int i = n; i >= 0; i--)
    {
        for(int j = m; j >= 0; j--)
        {
            if(i == n || j == m)
            {
                dp[i][j] = 0;
                continue;
            }
            
            if(text1[i] == text2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

// print the LCS
int longestCommonSubsequence(string text1, string text2) 
{
    int n = text1.length();
    int m = text2.length();
    
    vector<vector<string>>dp(n + 1, vector<string>(m + 1, ""));
    
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            if(text1[i] == text2[j])
                dp[i][j] = string(1, text1[i]) + dp[i + 1][j + 1];
            else
                dp[i][j] = (dp[i + 1][j].length() > dp[i][j + 1].length()) ? dp[i + 1][j] : dp[i][j + 1];
        }
    }
    cout<<dp[0][0]<<"\n";
    return dp[0][0].length();
}

