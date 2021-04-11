int numDecodings(string s) 
{
    int n = s.length();
    int M = 1e9 + 7;
    
    vector<long long>dp(n + 1, 0);
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
        if(ch1 == '*') 
            dp[i] = (dp[i] % M * 9 % M) % M;
        
        if(i + 1 < n)
        {
            char ch2 = s[i + 1];
            long long num = 0;
            
            if(ch1 == '*' && ch2 == '*')
                num = ((15 % M) * (dp[i + 2] % M)) % M; 
            
            else if(ch2 == '*')
            {
                if(ch1 == '1')
                    num = ((9 % M) * (dp[i + 2] % M)) % M;
                
                else if(ch1 == '2')
                    num = ((6 % M) * (dp[i + 2] % M)) % M;
            }
            
            else if(ch1 == '*')
            {
                if(ch2 - '0' <= 6)
                    num = ((2 % M) * (dp[i + 2] % M)) % M;
                
                else 
                    num = dp[i + 2];
            }
            
            else if((ch1 - '0') * 10 + (ch2 - '0') <= 26) 
                num = dp[i + 2];
            
            dp[i] = ((dp[i] % M) + (num % M)) % M;
        }
    }
    
    return (int)dp[0];
}