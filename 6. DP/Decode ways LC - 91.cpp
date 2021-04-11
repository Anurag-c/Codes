int numDecodings(string s) 
{    
    int n = s.length();
    if(n != 0 && s[0] == '0') return 0;
    
    vector<int>dp(n + 1, 0);
    dp[n] = 1;
    
    for(int i = n - 1; i >= 0; i--)
    {
        char ch1 = s[i];
        if(ch1 == '0')
        {
            dp[i] = 0;
            continue;
        }
        
        dp[i] = dp[i + 1];
        if(i + 1 < n)
        {
            char ch2 = s[i + 1];
            int num = (ch1 - '0') * 10 + (ch2 - '0');
            if(num <= 26) dp[i] += dp[i + 2];
        }
    }
    
    return dp[0];
}

