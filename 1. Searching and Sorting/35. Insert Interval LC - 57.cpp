
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    int n = intervals.size();
    if(n == 0) return {newInterval};
    
    
    for(int i = 0 ; i < n ; i++)
    {
        if(newInterval[0] < intervals[i][0])
        {
            intervals.insert(intervals.begin() + i,newInterval);
            break;
        }
    }
    if(intervals.size() == n) intervals.push_back(newInterval);
    n++;
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    vector<vector<int>>ans;
    for(int i = 1 ; i < n ; i++)
    {
        int new_start = intervals[i][0];
        int new_end = intervals[i][1];
        if(new_start <= end) end = max(end, new_end);
        else
        {
            ans.push_back({start,end});
            start = new_start;
            end = new_end;
        }
    }
    ans.push_back({start,end});
    return ans;
}