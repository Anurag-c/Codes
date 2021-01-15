
vector<vector<int>>ans;
void comb(int idx, int k, int target, vector<int>& curr)
{
    if(target == 0)
    {
        if(k == 0) ans.push_back(curr);
        return;
    }
    
    for(int i = idx ; i <= 9; i++)
    {
        if(target - i >= 0)
        {
            curr.push_back(i);
            comb(i + 1, k - 1, target - i, curr);
            curr.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) 
{
    vector<int>curr;
    comb(1, k, n, curr);
    return ans;
}