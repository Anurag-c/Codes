vector<string>result;
    
int getNum(string& s)
{
    int ans = 0;
    for(int i = 0; i < s.length(); i++) ans = (ans * 10) + (s[i] - '0');
    return ans;
}

bool valid(string& x)
{
    int n = getNum(x);
    int m = x.length();
    return (m == 1 && n <= 9) || (m == 2 && n <= 99 && n >= 10) || (m == 3 && n <= 255 && n >= 100);
}

void solve(string s, int dots, string ans)
{
    if(s.length() == 0)
    {
        ans.pop_back();
        if(dots == 4) result.push_back(ans);
        return;
    }
    string x;
    for(int i = 0; i < s.length() && i < 3; i++)
    {
        x += s[i];
        if(valid(x) && dots <= 3) solve(s.substr(i + 1), dots + 1, ans + x + ".");
    }
}
vector<string> restoreIpAddresses(string s) 
{
    solve(s, 0, "");
    return result;
}