
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    if(intervals.size() == 0 || intervals[0].size() == 0) return {};
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    
    for(int i = 1; i < n; i++)
    {
        int curr_start = intervals[i][0];
        int curr_end = intervals[i][1];
        
        if(curr_start <= end) end = max(end, curr_end);
        else
        {
            ans.push_back({start,end});
            start = curr_start;
            end = curr_end;
        }
    }
    ans.push_back({start,end});
    return ans;
}