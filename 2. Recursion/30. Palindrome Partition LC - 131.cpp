bool isPalindrome(string x)
{
    string s = x;
    reverse(x.begin(),x.end());
    return (s == x);
}
void solve(vector<vector<string>> &result, string s, vector<string> &currentList) 
{
    if(s.length() == 0) result.push_back(currentList);
    
    string x;
    for (int i = 0; i < s.length(); i++) 
    {
        x += s[i];
        if(isPalindrome(x)) 
        {
            currentList.push_back(x);
            solve(result, s.substr(i + 1), currentList);
            currentList.pop_back(); // backtrack
        }
    }
}
vector<vector<string>> partition(string s) 
{
    vector<vector<string>>result;
    vector<string>currentList;
    solve(result, s, currentList);
    return result;
}

//bring answers sol
bool isPalindrome(string x)
{
    string s = x;
    reverse(x.begin(),x.end());
    return (s == x);
}

vector<vector<string>> partition(string s) 
{
    if(s.length() == 0) return {{}};
    vector<vector<string>>ans;
    string x;
    for(int i = 0; i < s.length(); i++)
    {
        x += s[i];
        if(isPalindrome(x))
        {
            vector<vector<string>>small = partition(s.substr(i + 1));
            for(int i = 0; i < small.size(); i++) small[i].insert(small[i].begin(),x);
            ans.insert(ans.end(), small.begin(), small.end());
        }
    }
    return ans;
}

// memo for prev sol
bool isPalindrome(string x)
{
    string s = x;
    reverse(x.begin(),x.end());
    return (s == x);
}
vector<vector<string>> solve(string s, int idx, vector<vector<vector<string>>>& dp) 
{
    if(s.length() <= idx) return {{}};
    if(dp[idx].size() != 0) return dp[idx];
    
    vector<vector<string>>ans;
    string x;
    for(int i = idx; i < s.length(); i++)
    {
        x += s[i];
        if(isPalindrome(x))
        {
            vector<vector<string>>small = solve(s, i + 1, dp);
            for(int i = 0; i < small.size(); i++) small[i].insert(small[i].begin(),x);
            ans.insert(ans.end(), small.begin(), small.end());
        }
    }
    return dp[idx] = ans;
}

vector<vector<string>> partition(string s) 
{
    vector<vector<vector<string>>>dp(s.length() + 1);
    return solve(s, 0, dp);
}