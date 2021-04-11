
int numDistinct(string s, string t) 
{
    int m = s.length();
    int n = t.length();
    
    vector<long long>dp(n, 0);
    
    for(int i = m - 1; i >= 0; i--)
    {
        int diag = 1;
        for(int j = n - 1; j >= 0; j--)
        {   
            if(m - i < n - j) break;
            
            int old_dpj = dp[j];
            
            if(s[i] == t[j])
                dp[j] += diag;
            
            diag = old_dpj;
        }
    }
    
    return dp[0];
}