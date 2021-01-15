
vector<vector<int>>ans;
void comb(int idx, int k, int n, vector<int>& curr)
{
    if(k == 0)
    {
        ans.push_back(curr);
        return;
    }
    
    for(int i = idx ; i <= n; i++)
    {
        curr.push_back(i);
        comb(i + 1, k - 1, n, curr);
        curr.pop_back(); 
    }
}

vector<vector<int>> combine(int n, int k) 
{
    vector<int>curr;
    comb(1, k, n, curr);
    return ans;
}