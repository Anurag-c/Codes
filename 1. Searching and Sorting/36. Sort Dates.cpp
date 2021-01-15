
#include <bits/stdc++.h>
using namespace std;

void sort(vector<vector<int>>& dates, int j)
{
    vector<vector<vector<int>>>count(2100);
    for(int i = 0; i < dates.size(); i++)
    {
        count[dates[i][j]].push_back(dates[i]);
    }
    int i = 0;
    for(vector<vector<int>> arr : count)
    {
        for(vector<int> date : arr)
        {
            dates[i] = date;
            i++;
        }
    }
}

int main() {
    
    vector<vector<int>>dates = {{20,  1, 2014},
                    {25,  1, 2014},
                    { 3, 1, 2014},
                    {18, 1, 2014},
                    {19,  1, 2014},
                    { 9,  1, 2013}};
    sort(dates,0);
    sort(dates,1);
    sort(dates,2);
    for(vector<int> date : dates)
    {
        for(int i : date) cout<<i<<" ";
        cout<<"\n";
    }
}
