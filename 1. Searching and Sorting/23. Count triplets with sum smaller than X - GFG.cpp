
//https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
long long countTriplets(long long arr[], int n, long long sum)
{
    long long ans = 0;
    sort(arr,arr+n);
    for(int i = 0 ; i < n ; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while(j < k)
        {
            long long x = arr[i] + arr[j] + arr[k];
            if(x >= sum) k--;
            else
            {
                ans += (k - j);
                j++;
            }
        }
    }
    return ans;
}