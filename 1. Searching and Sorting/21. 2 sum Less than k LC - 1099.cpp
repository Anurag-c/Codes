
int twoSumLessThanK(vector<int>& arr, int k) 
{
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(low < high)
    {
        int sum = arr[low] + arr[high];
        if(sum < k)
        {
            ans = max(ans,sum);
            low++;
        }
        else high--;
    }
    return ans;
}