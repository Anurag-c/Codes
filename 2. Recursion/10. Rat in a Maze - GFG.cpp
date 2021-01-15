// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

vector<int>dr = {-1, 1, 0, 0}; 
vector<int>dc = {0, 0, -1, 1};
vector<string>ch = {"U", "D", "L", "R"};

void solve(int m[MAX][MAX], int sr, int sc, int n, string psf, vector<string>& ans)
{
    if(sr == n && sc == n)
    {
        ans.push_back(psf);
        return;
    }

    m[sr][sc] = -1;
    for(int i = 0 ; i < 4; i++)
    {
        int new_r = sr + dr[i];
        int new_c = sc + dc[i];
        if(new_r >= 0 && new_r <= n && new_c >=0 && new_c <= n && m[new_r][new_c] == 1)
            solve(m, new_r, new_c, n, psf + ch[i], ans);
    }
    m[sr][sc] = 1;
}

vector<string> printPath(int m[MAX][MAX], int n) 
{
    if(m[0][0] == 0) return {};
    vector<string>ans;
    solve(m, 0, 0, n-1, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
}