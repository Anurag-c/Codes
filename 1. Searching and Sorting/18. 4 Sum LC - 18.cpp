vector<vector<int>> fourSum(vector<int>& arr, int k) 
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>>ans;
    for(int i = 0; i < n - 3; i++)
    {
        if(i != 0 && arr[i-1] == arr[i]) continue;
        
        for(int j = i + 1 ; j < n -2 ; j++)
        {
            int low = j + 1;
            int high = n - 1;
            if(j != i + 1 && arr[j-1] == arr[j]) continue; // important !! dont mistake with j != 0
            while(low < high)
            {
                if(arr[i] + arr[j] + arr[low] + arr[high] == k) 
                {
                    ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                    low++;
                    high--;
                    while(low < high && arr[low] == arr[low - 1]) low++;
                }
                else if(arr[i] + arr[j] + arr[low] + arr[high] < k) low++;
                else high--;
            }
        }
    }
    return ans;
}