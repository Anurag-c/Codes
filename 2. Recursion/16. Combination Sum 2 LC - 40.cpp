
vector<vector<int>>ans;
void comb(vector<int>& arr, int idx, int target, vector<int>& curr)
{
    if(target == 0)
    {
        ans.push_back(curr);
        return;
    }
    
    for(int i = idx ; i < arr.size(); i++)
    {
        if(i > idx && arr[i - 1] == arr[i]) continue;
        if(target - arr[i] >= 0)
        {
            curr.push_back(arr[i]);
            comb(arr, i + 1, target - arr[i], curr);
            curr.pop_back(); 
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
{
    vector<int>curr;
    sort(arr.begin(),arr.end());
    comb(arr,0,target,curr);
    return ans;
}