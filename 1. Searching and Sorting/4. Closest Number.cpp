
int closestNumberIndex(vector<int> &arr, int num)
{
    int n = arr.size() - 1;
    if(num <= arr[0] || num >= arr[n]) return num <= arr[0] ? 0 : n;

    int start = 0;
    while(start <= n)
    {
        int mid = (start + n)/2;
        if(arr[mid] == num) return mid;
        else if(arr[mid] < num) start = mid + 1;
        else n = mid - 1;
    }
    return (arr[start] - num < num - arr[end]) ? start : n;
} 