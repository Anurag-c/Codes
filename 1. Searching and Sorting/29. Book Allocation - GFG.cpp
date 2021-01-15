
//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

int isPossible(int *arr,int n,int pages,int m)
{
    int curr_pages = 0;
    int students = 1;
    for(int i = 0 ; i<n ; i++)
    {
        curr_pages += arr[i];
        if(curr_pages > pages)
        {
            curr_pages = arr[i];
            students++;
            if(students > m) return false;
        }
    }
    return true;
}

int findPages(int *arr, int n, int m) 
{
    if(n < m) return -1;
    int start = *max_element(arr,arr+n);
    int end = 0;
    for(int i = 0; i < n ; i++) end += arr[i];
    while(start < end)
    {
        int mid =   start + ((end - start)/2);
        if(isPossible(arr,n,mid,m)) end = mid;
        else start = mid + 1;
    }
    return end;
}