#include<bits/stdc++.h>
using namespace std;

vector<int>dr = {-1, 0, 1, 0};
vector<int>dc = {0, 1, 0, -1};
vector<string>ch = {"U", "R", "D", "L"}; 
 
class Pair
{
    public:
    int length;
    string path;
    Pair()
    {
        length = 0;
        path = "";
    }
    Pair(int length, string path)
    {
        this->length = length;
        this->path = path;
    }
};

Pair solve(int sr, int sc, int m, int n, vector<vector<int>>& maze, int len)
{
    if(sr == m && sc == n) return new Pair();
    
    maze[sr][sc] = -1;
    int ans = INT_MAX;
    for(int i = 0 ; i < 4; i++)
    {
        int new_r = sr + dr[i];
        int new_c = sc + dc[i];
        if(new_r >= 0 && new_r <= m && new_c >=0 && new_c <= n && maze[new_r][new_c] == 1)
            ans = min(ans, solve(new_r, new_c, m, n, maze, len + 1));
    }
    maze[sr][sc] = 1;
    return ans;
}  

int main()
{
    vector<vector<bool>>vis(3,vector<bool>(3,false));
    cout<<solve(0, 0, m, n, maze, 0);
}