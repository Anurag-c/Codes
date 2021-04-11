int findNumberOfLIS(vector<int>& arr) 
{
    int n = arr.size();
    
    vector<int>dp(n, 1);
    vector<int>nums(n, 1);
    
    int lis = 1;
    int numLis = 1;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[i] > arr[j])
            {
                if(dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    nums[i] = nums[j];
                }
                else if(dp[i] == 1 + dp[j])
                    nums[i] += nums[j];
            }   
        }
        if(lis == dp[i]) numLis += nums[i];
        else if(lis < dp[i])
        {
            lis = dp[i];
            numLis = nums[i];
        }
    }
    
    return numLis;
}