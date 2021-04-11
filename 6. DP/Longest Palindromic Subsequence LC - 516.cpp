
int LongestPalindromicSubseq(string& s, int l, int r, vector<vector<int>>& dp)
{
    if(l >= r)
        return dp[l][r] = (l == r) ? 1 : 0;
    

    if(s[l] == s[r])
        return dp[l][r] = 2 + LongestPalindromicSubseq(s, l + 1, r - 1, dp);

    return dp[l][r] = max(LongestPalindromicSubseq(s, l + 1, r, dp), LongestPalindromicSubseq(s, l, r - 1, dp)); 
}

// Tabulation

int longestPalindromeSubseq(string& s)
{
    int n = s.length();

    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int gap = 0; gap < n; gap++)
    {
        for(int i = 0, j = gap; j < n; j++, i++)
        {
            if(i >= j)
            {
                dp[i][j] = (i == j) ? 1 : 0;
                continue;
            }
            
            if(s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];

            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}
