
#include<bits/stdc++.h>
using namespace std;

//infinity coins
int coinChangePermutation_Memo(int target, vector<int>& coins, vector<int>& dp)
{
    if(target == 0) return dp[target] = 1;
    
    if(dp[target] != -1) return dp[target];
    
    int count = 0;
    for(int i = 0; i < coins.size(); i++)
    {
        if(target - coins[i] >= 0)
            count += coinChangePermutation_Memo(target - coins[i], coins, dp);
    }

    return dp[target] = count;
}

int coinChangePermutation_Tab(int target, vector<int>& coins)
{
    vector<int>dp(target + 1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= target; i++)
    {
        int tar = i;
        for(int j = 0; j < coins.size(); j++)
        {
            if(tar - coins[j] >= 0)
                dp[tar] += dp[tar - coins[j]];
        }
    }
    return dp[target];
}

int coinChangeCombination_Memo1(int target, int idx, vector<int>& coins, vector<vector<int>>& dp)
{
    if(target == 0) 
        return dp[idx][target] = 1;

    int count = 0;
    for(int i = idx; i < coins.size(); i++)
    {
        if(target - coins[i] >= 0)
            count += coinChangeCombination_Memo(target - coins[i], i, coins, dp);
    }
    return dp[idx][target] = count;
}

//consider , not consider
long long coinChangeCombination_Memo2(vector<int>& coins, int target,  int idx, vector<vector<long long>>& dp)
{
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(idx >= coins.size()) return 0; 
    
    if(dp[idx][n] != -1) return dp[idx][n];
    
    long long ans = coinChangeCombination_Memo2(coins, target - S[idx], idx, dp) + coinChangeCombination_Memo2(coins, target, idx + 1, dp);
    
    return dp[idx][n] = ans;
}

long long int coinChangeCombination_Tab(int coins[], int m, int n )
{
   vector<vector<long long>>dp(m + 1, vector<long long>(n + 1, 0));
  
   for(int target = 0; target <= n; target++)
   {
        for(int idx = m - 1; idx >= 0; idx--)
        {
            if(target == 0) dp[idx][0] = 1;
            
            else if(target - coins[idx] >= 0)
                dp[idx][target] = dp[idx][target - coins[idx]] + dp[idx + 1][target];
        }
   }
   return dp[0][n];
}

int coinChangeCombination_1D(vector<int>& coins, int target)
{
    vector<int>dp(target + 1, 0);
    dp[0] = 1;
    
    for(int j = 0; j < coins.size(); j++)
    {
        for(int i = 1; i <= target; i++)
        {
            int tar = i;
            if(tar - coins[j] >= 0)
                dp[tar] += dp[tar - coins[j]];
        }
    }
    return dp[target];
}

int main()
{
    vector<int>coins = {2, 3, 5, 7};
    vector<int>dp(11, -1);
    cout<<coinChangePermutation(10, coins, dp);
}
    