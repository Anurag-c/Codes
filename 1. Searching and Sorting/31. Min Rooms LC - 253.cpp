int minMeetingRooms(vector<vector<int>>& intervals) 
{
    int n = intervals.size();
    vector<int>start_times,end_times;
    for(vector<int>se : intervals)
    {
        start_times.push_back(se[0]);
        end_times.push_back(se[1]);
    }
    sort(start_times.begin(), start_times.end());
    sort(end_times.begin(), end_times.end());
 
    int start = 0;
    int end = 0;
    int rooms = 0;
    int total_rooms = 0;
    while(start < n && end < n)
    { 
        if(start_times[start] < end_times[end])
        {
            rooms++;
            total_rooms = max(total_rooms, rooms);
            start++;
        }
        else
        {
            rooms--;
            end++;
        }
    }
    return total_rooms;
}

//line sweep

int minMeetingRooms(vector<vector<int>>& intervals) 
{
    int n = intervals.size();
    map<int,int>count;
    for(int i = 0; i < n; i++)
    {
        count[intervals[i][0]] += 1;
        count[intervals[i][1]] -= 1;
    }
    int rooms = 0;
    int ans = 0;
    for(auto i : count)
    {
        rooms += i.second;
        ans = max(ans,rooms);
    }
    return ans;
}

