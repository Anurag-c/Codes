#include<bits/stdc++.h>
using namespace std;

void solve(string s, unordered_set<string>& hm, int idx, string ans)
{
    if(idx == s.length())
    {
        cout<<ans<<"\n";
        return;
    }

    string x = "";
    for(int i = idx; i < s.length(); i++)
    {
        x += s[i];
        if(hm.find(x) != hm.end())
            solve(s, hm, i + 1, ans + x + " ");
    }
}

int main()
{
    int n;
    cin>>n;
    unordered_set<string>hm;
    for (int i = 0; i < n; i++) 
    {
        string x;
        cin>>x;
        hm.insert(x);
    }
    string sentence;
    cin>>sentence;
    solve(sentence, hm, 0, "");
}

// rec + memo
bool solve(string s, unordered_set<string>& hm, int idx, vector<int>& dp)
{
    if(idx == s.length()) return true;
    if(dp[idx] != -1) return dp[idx];
    
    string x = "";
    for(int i = idx; i < s.length(); i++)
    {
        x += s[i];
        if(hm.find(x) != hm.end() && solve(s, hm, i + 1, dp)) return dp[idx] = true;
    }
    return dp[idx] = false;
}
bool wordBreak(string s, vector<string>& wordDict) 
{
    unordered_set<string>hm;
    vector<int>dp(s.length(), -1);
    for (int i = 0; i < wordDict.size(); i++) hm.insert(wordDict[i]);
    return solve(s, hm, 0, dp);
}