
int search(vector<int>& arr, int target) 
{
    int start = 0, end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == target) return mid;
        else if(arr[start] <= arr[mid])
        {
            if(target >= arr[start] && target < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        else
        {
            if(target > arr[mid] && target <= arr[end]) start = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;   
}