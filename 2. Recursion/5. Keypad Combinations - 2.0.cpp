#include<bits/stdc++.h>
using namespace std;

string codes = { ".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz", "+-*", "/%^" };

int solve(string s, int idx, string ans)
{
    if(idx == str.length()) {
        cout<<ans<<"\n";
        return 1;
    }
    
    int count = 0;
    int num = s[0] - '0';
    for(int i = 0 ; i < codes[num].length() ; i++) {
        count += solve(s, idx + 1, ans + codes[num][i]);
    }
    
    if(s.length > 2) {
        num = ((s[0] - '0') * 10) + (s[1] - '0');
        if(num == 10 || num == 11) {
            for(int i = 0 ; i < codes[num].length() ; i++) { 
                count += solve(s, idx + 2, ans + codes[num][i]);
            }
        }
    }
    return count;
}