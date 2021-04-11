int LIS(vector<int>& arr, vector<int>& dp)
{
    int n = arr.size();
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

void dfs(vector<int>& arr, vector<vector<int>>& hm, int index, int len, string ans)
{
    if(len == 1)
    {
        cout<<ans + to_string(arr[index])<<"\n";
        return;
    }

    for(int idx : hm[len - 1])
    {
        if(idx > index) break;
        else if(arr[index] > arr[idx])
            dfs(arr, hm, idx, len - 1, ans + to_string(arr[index]) + ", "); 
    
    }
}

void printAll(vector<int>& arr) 
{
    int n = arr.size();
    vector<int>dp(n, 1);
    int lis = LIS(arr, dp);
    
    vector<vector<int>>hm(lis + 1);
    
    for(int i = 0; i < n; i++)
        hm[dp[i]].push_back(i);

    for(int i = 0; i < n; i++)
    {
        if(dp[i] == lis)
            dfs(arr, hm, i, lis, "");   
    }
}
//[0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15,14]
