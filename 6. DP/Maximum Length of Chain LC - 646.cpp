bool static compare(vector<int>& arr, vector<int>& brr)
{
    return arr[1] < brr[1];
}

int findLongestChain(vector<vector<int>>& pairs) 
{
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    
    int ans = 1;
    int prev = pairs[0][1];
    for(int i = 1; i < n; i++)
    {
        if(pairs[i][0] > prev) 
        {
            ans++;
            prev = pairs[i][1];
        }
    }
    return ans;
}