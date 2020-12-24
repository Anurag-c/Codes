vector<vector<int>> threeSum(vector<int>& arr) 
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    vector<vector<int>>ans;
    
    for(int i = 0 ; i < n - 2 ; i++)
    {
        if(i != 0 && arr[i-1] == arr[i]) continue; // handling duplicates
        
        // two Sum on rem part of array
        int low = i + 1;
        int high = n - 1;
        while(low < high)
        {
            int sum = arr[i] + arr[low] + arr[high];
            if(sum == 0) 
            {
                ans.push_back({arr[i], arr[low++], arr[high--]});
                while(low < high && arr[low] == arr[low - 1]) low++; // handling duplicates
                while(low < high && arr[high] == arr[high + 1]) high--;
            }
            else if(sum < 0) low++;
            else high--;
        }
    }
    return ans;   
}