
int maxOperations(vector<int>& nums, int k) 
{
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        int complement = k - current;
        if (map[complement] > 0) {
            // remove complement from the map
            map[complement] = map[complement] - 1;
            count++;
        } else {
             // add current element in the map
            map[current] = map[current] + 1;
        }
    }
    return count;
}

int maxOperations(vector<int>& nums, int k) 
{
    unordered_map<int,int>hm;
    int n = nums.size();
    for(int i = 0; i < n; i++) hm[nums[i]]++;
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        int b = nums[i];
        int a = k - b;
        if(hm[a] >= 1 && hm[b] >=1)
        {
            if(a == b && hm[a] == 1) continue;
            hm[a]--;
            hm[b]--;
            c++;
        }
    }
    return c;
}