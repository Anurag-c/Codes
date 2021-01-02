
vector<vector<int>>permutations;
void solve(vector<int>& nums,vector<int>& ans)
{
    if(ans.size() == nums.size())
    {
        permutations.push_back(ans);
        return;
    }
    
    for(int i = 0 ; i < nums.size() ; i++)
    {
        if(i!=0 && nums[i-1] == nums[i]) continue;
        if(nums[i] != -11)
        {
            ans.push_back(nums[i]);
            nums[i] = -11;
            solve(nums,ans);
            nums[i] = ans[ans.size() - 1];
            ans.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    vector<int>ans;
    solve(nums,ans);
    return permutations;
}