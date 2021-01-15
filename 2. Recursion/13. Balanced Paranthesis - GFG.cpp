
// https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1

vector<string>ans;
void solve(int open, int close, int n, string bracket)
{
    if(open == n && close == n)
    {
        ans.push_back(bracket);
        return;
    }
    
    if(open > close) solve(open,close + 1, n, bracket + ')');
    if(open < n) solve(open + 1,close, n, bracket + '(');
}

vector<string> AllParenthesis(int n) 
{
    ans.clear();
    solve(0, 0, n, "");
    return ans;
}