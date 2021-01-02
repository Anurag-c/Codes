
string hm[27] = {"","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    
int solve(string s, string ans)
{
    if(s.length() == 0) 
    {
        cout<<ans<<"\n";
        return 1;
    }
    
    if(s[0] == '0') return 0;
    
    int count = 0;
    count += solve(s.substr(1), ans + hm[s[0] - '0']);
    if(s.length() > 1)
    {
        int num = ((s[0] - '0') * 10) + (s[1] - '0');
        if(num <= 26) count += solve(s.substr(2), ans + hm[num]);
    }
    return count;
}

int numDecodings(string s) 
{
    return solve(s, "");
}