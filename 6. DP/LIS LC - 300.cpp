// using dp - O(n^2)
int LIS(vector<int>& arr)
{
    int n = arr.size();
    vector<int>dp(n, 1);

    int lis = 1;
    for(int i = 0; i < n; i++)
    {
        int maxLen = 1;
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[i] > arr[j])
                maxLen = max(maxLen, 1 + dp[j]);
        }
        dp[i] = maxLen;
        lis = max(lis, dp[i]);
    }
    return lis;
}

// using Binary Search - O(nlogn)
int replacePos(vector<int>& arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] < k) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

int lengthOfLIS(vector<int>& nums) 
{
    vector<int>arr;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        int idx = replacePos(arr,nums[i]);
        if(idx == arr.size()) arr.push_back(nums[i]);
        else arr[idx] = nums[i];
    }
    return arr.size();
}
