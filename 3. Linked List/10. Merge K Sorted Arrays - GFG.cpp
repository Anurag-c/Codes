vector<int> merge(vector<int>& list1, vector<int>& list2)
{
    vector<int>ans;
    int i = 0;
    int j = 0;
    int n = list1.size();
    int m = list2.size();
    while(i < n && j < m)
    {
        if(list1[i] < list2[j])
        {
            ans.push_back(list1[i]);
            i++;
        }
        else
        {
            ans.push_back(list2[j]);
            j++;
        }
    }
    while(i < n)
    {
        ans.push_back(list1[i]);
        i++;
    }
    while(j < m)
    {
        ans.push_back(list2[j]);
        j++;
    }
    return ans;
}

vector<int> mergeK(vector<vector<int>>& lists)
{
    int k = lists.size();
    int interval = 1;
    while(interval < k)
    {
        for(int i = 0; i < k - interval; i += 2 * interval)
        {
            lists[i] = merge(lists[i], lists[i + interval]);
        }
        interval = 2 * interval;
    }
    return lists[0];
}