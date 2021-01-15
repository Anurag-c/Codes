
// combinations method Nc0 + Nc1 + ....
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
        if(target - arr[i] >= 0)
        {
            curr.push_back(arr[i]);
            comb(arr, i, target - arr[i], curr);
            curr.pop_back(); 
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) 
{
    vector<int>curr;
    comb(arr,0,target,curr);
    return ans;
}

// 2^n (consider, not consider) method
vector<vector<int>>ans;
void comb(vector<int>& arr, int idx, int target, vector<int>& curr)
{
    if(idx == arr.size())
    {
        if(target == 0) ans.push_back(curr);
        return;
    }
    
    if(target - arr[idx] >= 0)
    {
        curr.push_back(arr[idx]);
        comb(arr, idx, target - arr[idx], curr);
        curr.pop_back(); 
    }
    comb(arr, idx + 1, target, curr);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) 
{
    vector<int>curr;
    comb(arr,0,target,curr);
    return ans;
}

