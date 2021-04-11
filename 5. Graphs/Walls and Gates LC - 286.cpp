
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
    
void wallsAndGates(vector<vector<int>>& rooms) 
{
    int m = rooms.size();
    int n = rooms[0].size();
    
    queue<int>q;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(rooms[i][j] == 0)
                q.push(i * n + j);
        }
    }
    
    int dis = 1;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int combined = q.front();
            q.pop();
            
            int r = combined / n;
            int c = combined % n;
            
            for(int i = 0; i < 4; i++)
            {
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                
                if(new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && rooms[new_r][new_c] == 2147483647)
                {
                    rooms[new_r][new_c] = dis;
                    q.push(new_r * n + new_c);
                }  
            }
        }
        dis++;
    }
}

