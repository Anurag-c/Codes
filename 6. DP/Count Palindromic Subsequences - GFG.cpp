int m = 1e9 + 7;
    
long long solve(string& s, vector<vector<long long>>& dp, int l, int r)
{
    if(l >= r)
        return dp[l][r] = (l == r) ? 1 : 0;
    
    if(dp[l][r] != -1) return dp[l][r];
    
    long long a = solve(s, dp, l + 1, r);
    long long b = solve(s, dp, l, r - 1);
    long long c = solve(s, dp, l + 1, r - 1);
    
    long long sum = (a % m + b % m) % m;
    
    return dp[l][r] = (s[l] == s[r]) ? (sum % m + 1 % m) % m : (sum % m - c % m + m) % m;
}