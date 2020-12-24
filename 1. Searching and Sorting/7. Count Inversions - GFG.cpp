
//GFG LINK : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
//SI LINK : https://www.hackerrank.com/contests/smart-interviews/challenges/si-smaller-elements

long long merge(int arr[], int low, int mid, int high)
{
    long long c = 0;
    int i = low; // start of 1st Sorted Array
    int j = mid + 1; // start of 2nd Sorted Array
    int temp[high - low + 1];
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++]=arr[i++];
            // c += high - j + 1; in case of i > j and a[i] > a[j]
        }
        else
        {
            temp[k++]=arr[j++];
            c += mid - i + 1; // mid is the ending pos of 1st sorted array
        }
    }
    while(i <= mid) temp[k++]=arr[i++];
    while(j <= high) temp[k++]=arr[j++];
    for(int i = low; i <= high; i++) arr[i] = temp[i - low];
    return c;
}

long long ms(int arr[],int low ,int high)
{
    if(low >= high) return 0;
    long long c = 0;
    int mid = (low+high)/2;
    c += ms(arr, low, mid); // sort left and bring inversions
    c += ms(arr, mid+1, high); // sort right and bring inversions
    c += merge(arr, low, mid, high); // combine left, right and bring inversions
    return c;
} 

