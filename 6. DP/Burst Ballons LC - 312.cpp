int maxCoins(vector<int>& arr) 
{
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(n, 0));
    
    for(int gap = 0; gap < n; gap++)
    {
        for(int start = 0, end = gap; end < n; start++, end++)
        {
            int maxCost = INT_MIN;        
            for(int cut = start; cut <= end; cut++)
            {
                int left = (start - 1 < 0) ? 1 : arr[start - 1] ;
                int right = (end + 1 >= arr.size())  ? 1 : arr[end + 1];
                
                int lans = (cut > start) ? dp[start][cut - 1] : 0;
                int rans = (cut < end) ? dp[cut + 1][end] : 0;
                
                maxCost = max(maxCost, lans + rans + left * arr[cut] * right);
            }
            dp[start][end] = maxCost; 
        }
    }
    
    return dp[0][n - 1];
}