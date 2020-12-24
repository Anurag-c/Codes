// GFG Link : https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
vector<int> floor_ceil(vector<int>& arr, int target) 
{
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == target) return {mid,mid};
        else if(arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return {end,start};
}