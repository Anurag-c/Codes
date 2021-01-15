// https://practice.geeksforgeeks.org/problems/special-matrix/0#
#include <bits/stdc++.h>
using namespace std;

long long numPaths(vector<vector<int>>& matrix, int sr, int sc, int dr, int dc, vector<vector<long long>>& dp)
{
    if(sr == dr && sc == dc) return 1;
    
    if(dp[sr][sc] != -1) return dp[sr][sc];
    
    long long count = 0;
    if(sc + 1 <= dc && matrix[sr][sc + 1] != 0)
        count += numPaths(matrix, sr, sc + 1, dr, dc, dp);
    count = count % 1000000007;
    
    if(sr + 1 <= dr && matrix[sr + 1][sc] != 0)
        count += numPaths(matrix, sr + 1, sc, dr, dc, dp);
    count = count % 1000000007;
    
    dp[sr][sc] = count;
    return count;
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,k;
	    cin>>n>>m>>k;
	    vector<vector<int>>matrix(n,vector<int>(m,1));
	    vector<vector<long long>>dp(n,vector<long long>(m,-1));
	    while(k--)
	    {
	        int r,c;
	        cin>>r>>c;
	        matrix[r-1][c-1] = 0;
	    }
	    cout<<numPaths(matrix, 0, 0, n-1, m-1, dp)<<"\n";
	}
	return 0;
}