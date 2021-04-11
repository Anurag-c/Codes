bool isMatch(string s, string p) 
{   
    int m = s.length();
    int n = p.length();
    
    if(n == 0)
    {
        if(m == 0) return true;
        return false;
    }
    
    string x;
    x.push_back(p[0]);
    
    for(int i = 1; i < n; i++)
    {
        if(p[i] == '*' && p[i - 1] == '*')
            continue;
        
        x.push_back(p[i]);
    }
    
    n = x.length();
    p = x;

    vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = m; i >= 0; i--)
    {
        for(int j = n; j >= 0; j--)
        {
            if(i == m || j == n)
            {
                if((j == n - 1 && p[j] == '*') || (i == m && j == n)) 
                    dp[i][j] = 1;
                
                continue;
            }
            
            if(s[i] == p[j] || p[j] == '?')
                dp[i][j] = dp[i + 1][j + 1];
            
            else if(p[j] == '*')
                dp[i][j] =  dp[i + 1][j] || dp[i][j + 1];
        }
    }
    return dp[0][0];
} 

