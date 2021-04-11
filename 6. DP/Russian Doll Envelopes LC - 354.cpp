
//using DP
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
    int n = envelopes.size();
    vector<int>dp(n);
    sort(envelopes.begin(), envelopes.end());
    
    int ans = 1;
    for(int i = 0; i < n ; i++)
    {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--)
        {
            if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

//Using BS by Custom sort
int bs(vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

bool static compare(vector<int>& arr, vector<int>& brr)
{
    if(arr[0] == brr[0]) return arr[1] > brr[1];
    return arr[0] < brr[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) 
{
    int n = envelopes.size();
    vector<int>res;
    sort(envelopes.begin(), envelopes.end(), compare);
    
    res.push_back(envelopes[0][1]);
    
    for(int i = 1; i < n; i++)
    {
        int insert_pos = bs(res, envelopes[i][1]);
        if(insert_pos >= res.size()) res.push_back(envelopes[i][1]);
        else res[insert_pos] = envelopes[i][1];     
    }
    return res.size();
}

// [[4,5],[4,6],[6,7],[2,3],[1,1]] if you dont use compare fails here ans = 4 but op will be 4