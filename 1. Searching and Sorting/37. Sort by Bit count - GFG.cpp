
// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#
int set_bits(int a)
{
    int count = 0;
    while(a)
    {
        if (a & 1)
            count+= 1;
        a = a>>1;
    }
    return count;
}

void sortBySetBitCount(int arr[], int n)
{
    vector<vector<int>>count(33);
    for(int i = 0 ; i < n ; i++)
    {
        count[set_bits(arr[i])].push_back(arr[i]);
    }
    int i = 0;
    for(int j = 32 ; j >= 0 ; j--)
    {
        for(int x : count[j])
        {
            arr[i] = x;
            i++;
        }
    }
}