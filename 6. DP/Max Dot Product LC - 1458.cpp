class Solution 
{
    int maxProd(vector<int>& nums1, vector<int>& nums2, int m, int n, vector<vector<int>>& dp)
    {
        if(dp[m][n] != -1) return dp[m][n];
        
        int val = nums1[m - 1] * nums2[n - 1];
        int ans = val;
        
        if(m - 1 != 0 && n - 1 != 0)
            ans = max(ans, val + maxProd(nums1, nums2, m - 1, n - 1, dp));
        
        if(m - 1 != 0)
            ans = max(ans, maxProd(nums1, nums2, m - 1, n, dp));
        
        if(n - 1 != 0)
            ans = max(ans, maxProd(nums1, nums2, m, n - 1, dp));
        
        return dp[m][n] = ans;
    }

    public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return maxProd(nums1, nums2, m, n, dp);
    }
};