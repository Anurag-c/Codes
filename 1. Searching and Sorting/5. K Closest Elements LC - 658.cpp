int binarySearch(vector<int> &arr, int x)
{
    int start = 0,end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) start = mid + 1;
        else end = mid - 1;
    }
    return start;
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    int idx = binarySearch(arr, x); // returns where we could find the element
    int n = arr.size() - 1;
    int start = max(0, idx - k);
    int end = min(idx + k - 1, n);
    while((end - start) + 1 > k) // contraction of Window Size to k
    {
        if(x - arr[start] > arr[end] - x) start++;
        else end--;
    }
    vector<int>ans(arr.begin() + start, arr.begin() + end + 1); // return only the window of size k
    return ans;
}

