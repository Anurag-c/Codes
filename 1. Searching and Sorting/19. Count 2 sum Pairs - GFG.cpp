// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

int getPairsCount(int arr[], int n, int k) 
{
    unordered_map<int,int>hm;
    int c = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int b = arr[i];
        int a = k - b;
        if(hm.find(a) != hm.end()) c += hm[a];
        hm[b]++;
    }
    return c;
}