
int threeSumClosest(vector<int>& nums, int x) 
{
    sort(nums.begin(),nums.end());
    int ans = 10000;
    int n = nums.size();
    for(int  i = 0 ; i < n ; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while(low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];
            if(sum == x) return sum;
            if(sum > x) 
            {
                (min(abs(ans-x),sum-x) == sum-x)? ans = sum : ans = ans;
                high--;
            }
            else
            {
                (min(abs(ans-x),x-sum) == x-sum)? ans = sum : ans = ans;
                low++;
            }
        }
    }
    return ans;
}