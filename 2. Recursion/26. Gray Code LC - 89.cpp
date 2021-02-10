vector<int>ans;
vector<int> grayCode(int n) 
{
    if(n == 1) return {0,1};
    ans = grayCode(n-1);
    int x = ans.size();
    for(int i = x - 1 ; i >= 0 ; i--)
    {
        ans.push_back((1<<(n-1)) + ans[i]);
    }
    return ans;
}
