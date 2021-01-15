
// https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1#
long long countPairs(int X[], int Y[], int m, int n)
{
    vector<int>suffix(1001,0);
    for(int  i = 0 ; i < n; i++) suffix[Y[i]]++;
    
    for(int i = 1000; i >= 4 ; i--) suffix[i] += suffix[i+1];
    
    long long totalPairs = 0;
    for(int i = 0; i < m; i++)
    {
        if(X[i] == 0) continue;
        else if(X[i] == 1)
        {
            totalPairs += suffix[0];
            continue;
        }
        else if(X[i] == 2) totalPairs += suffix[5];
        else if(X[i] == 3) totalPairs += suffix[2] + suffix[4];
        else totalPairs += suffix[X[i] + 1];
        totalPairs += suffix[0] + suffix[1];
    }
    return totalPairs;
}