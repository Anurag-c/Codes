
//https://practice.geeksforgeeks.org/problems/quick-sort/1

int partition (int arr[], int low, int high)
{
    int pivot_index = low;
    int smaller = 0;
    for(int i = low + 1; i <= high ; i++)
    {
        if(arr[i] <= arr[pivot_index]) smaller++;
    }
    swap(arr[pivot_index], arr[low + smaller]);
    pivot_index = low + smaller;
    
    int left_start = low;
    int right_start = pivot_index + 1;
    int pivot_element = arr[pivot_index];
    
    while(left_start < pivot_index && right_start <= high)
    {
        if(arr[left_start] > pivot_element && arr[right_start] <= pivot_element)
        {
            swap(arr[left_start++], arr[right_start++]);
        }
        else if(arr[left_start] <= pivot_element && arr[right_start] > pivot_element)
        {
             left_start++;
             right_start++;
        }
        else if(arr[left_start] <= pivot_element) left_start++;
        else right_start++;
    }
    return pivot_index;
}

//randomized way
int partition (int arr[], int low, int high)
{
    int random = low + (rand() % (high - low));
    swap(arr[random],arr[low]);
    int pivot_index = low;
    int left_start = low + 1;
    for(int i = low + 1; i <= high ; i++)
    {
        if(arr[i] < arr[pivot_index])
        {
            swap(arr[left_start++],arr[i]);
        }
    }
    swap(arr[left_start - 1], arr[pivot_index]);
    pivot_index = left_start - 1;
    return pivot_index;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr,low,high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


