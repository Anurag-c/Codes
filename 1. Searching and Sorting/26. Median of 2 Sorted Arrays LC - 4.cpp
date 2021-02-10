double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    if(n > m) return findMedianSortedArrays(nums2,nums1);
    
    int low = 0, high = n;
    while(low <= high)
    {
        int part_n = (low + high)/2;
        int part_m = ((n + m + 1)/2) - part_n;
        
        int left_n = (part_n == 0) ? INT_MIN : nums1[part_n - 1];
        int left_m = (part_m == 0) ? INT_MIN : nums2[part_m - 1];
        
        int right_n = (part_n == n) ? INT_MAX : nums1[part_n];
        int right_m = (part_m == m) ? INT_MAX : nums2[part_m];
        
        int left = max(left_n, left_m);
        int right = min(right_n, right_m);
        
        if(left <= right)
        {
            if((n+m)%2 == 0) return (left + right)/2.0;
            return left;
        }
        else if(left_n > right_m) high = part_n - 1;
        else low = part_n + 1;
    }
    return -1;
}


