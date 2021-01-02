
string codes[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>combinations;

void solve(string s, string ans)
{
    if(s.length() == 0) 
    {
        combinations.push_back(ans);
        return;
    }
    int count = 0;
    int num = s[0] - '0';
    for(int i = 0 ; i < codes[num].length() ; i++) solve(s.substr(1), ans + codes[num][i]);
}
    
vector<string> letterCombinations(string digits) 
{
    if(digits.length() == 0) return {};
    solve(digits, "");
    return combinations;
}

// prefer wirting idx type solutions and return type solutions
// so that in case of possibility of memiozation it will be helpful
    
int solve(string s, int idx, string ans)
{
    if(idx == s.length()) 
    {
        combinations.push_back(ans);
        return 1;
    }
    int count = 0;
    int num = s[idx] - '0';
    for(int i = 0 ; i < codes[num].length() ; i++) count += solve(s, idx + 1, ans + codes[num][i]);
    return count;
}
    
vector<string> letterCombinations(string digits) 
{
    if(digits.length() == 0) return {};
    solve(digits, 0, "");
    return combinations;
}