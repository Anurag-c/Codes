#include<bits/stdc++.h>
using namespace std;

vector<int>dr = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int>dc = {0, 1, 1, 1, 0, -1, -1, -1};
vector<string>ch = {"U", "E", "R", "S", "D", "W", "L", "N"}; 

void solve(int sr, int sc, int m, int n, string ans, vector<vector<bool>>& vis)
{
    if(sr == m && sc == n)
    {
        cout<<ans<<"\n";
        return;
    }

    vis[sr][sc] = true;
    for(int i = 0 ; i < 8; i++)
    {
        int new_r = sr + dr[i];
        int new_c = sc + dc[i];
        if(new_r >= 0 && new_r <= m && new_c >=0 && new_c <= n && !vis[new_r][new_c])
            solve(new_r, new_c, m, n, ans + ch[i], vis);
    }
    vis[sr][sc] = false;
}  

int main()
{
    vector<vector<bool>>vis(3,vector<bool>(3,false));
    solve(0, 0, 2, 2, "", vis);
}