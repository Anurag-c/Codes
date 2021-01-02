
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    if(intervals.size() == 0 || intervals[0].size() == 0) return 0;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    int overlaps = 0;
    for(int i = 1; i < n; i++)
    {
        int new_start = intervals[i][0];
        int new_end = intervals[i][1];
        
        if(new_start < end)
        {
            overlaps++;
            end = min(end,new_end);
        }
        else end = new_end;
    }
    return overlaps;
}