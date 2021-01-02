
void sortColors(vector<int>& arr) 
{
    int start = 0;
    int mid = 0;
    int end = arr.size() - 1;
    
    while(mid <= end)
    {
        if(arr[mid] == 0) swap(arr[mid++],arr[start++]);
        else if(arr[mid] == 1) mid++;
        else if(arr[mid] == 2) swap(arr[end--],arr[mid]);
    }
}