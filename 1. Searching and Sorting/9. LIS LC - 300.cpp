
int replacePos(vector<int>& arr, int k)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] < k) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

int lengthOfLIS(vector<int>& nums) 
{
    vector<int>arr;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        int idx = replacePos(arr,nums[i]);
        if(idx == arr.size()) arr.push_back(nums[i]);
        else arr[idx] = nums[i];
    }
    return arr.size();
}