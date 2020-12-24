
vector<int> twoSum(vector<int>& nums, int k) 
{
    unordered_map<int, int>hm;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        int a = nums[i];
        int b = k - nums[i];
        if(hm.find(b) != hm.end()) return {hm[b], i};
        hm[a] = i;
    }
    return {};
}

vector<int> twoSum(vector<int>& arr, int target) 
{
    int low = 0, high = arr.size() - 1;
    while(low < high)
    {
        int sum = arr[low] + arr[high];
        if(sum == target) return {low + 1, high + 1};
        else if(sum < target) low++;
        else high--;
    }
    return {};
    
}
