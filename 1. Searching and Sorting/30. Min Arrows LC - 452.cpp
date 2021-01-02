
int findMinArrowShots(vector<vector<int>>& points) 
{
    if(points.size() == 0 || points[0].size() == 0) return 0;
    
    sort(points.begin(),points.end());
    int start = points[0][0];
    int end = points[0][1];
    int arrows = 1;
    for(int i = 1; i<points.size(); i++)
    {
        int new_start = points[i][0];
        int new_end = points[i][1];
        
        start = new_start;
        if(new_start <= end) end = min(end,new_end);
        else
        { 
            end = new_end;
            arrows++;
        }
    }
    return arrows;
}