
#include<bits/stdc++.h>
using namespace std;

void display(string& list, vector<int>& map)
{
    cout<<"{";
    for(int i = 0 ; i < list.size() ; i++)
    {
        cout<<list[i]<<" = "<<map[list[i] - 'a']<<", ";
    }
    cout<<"}\n";
}

int getNum(string s, vector<int>& map)
{
    int num = 0;
    for(int i = 0; i < s.length() ; i++)
        num = (num * 10) + map[s[i] - 'a'];
    return num;
}

int solve(string& list, int idx, vector<int>& map, int vis)
{
    if(idx == list.size())
    {
        int a = getNum("send", map) + getNum("more", map);
        int b = getNum("money", map);
        if(a == b) 
        {
            display(list, map);
            return 1;
        }
        return 0;
    }

    int count = 0;
    for(int i = 0 ; i <= 9 ; i++)
    {
        int mask = (1 << i);
        if(!(vis & mask))
        {
            vis ^= mask;
            map[list[idx] - 'a'] = i;
            
            count += solve(list,idx + 1, map, vis);
            
            vis ^= mask;
            map[list[idx] - 'a'] = -1;
        }
    }
    return count;
}

int main()
{
    vector<int>map(27, -1);
    string list = "sendmory";
    cout<<solve(list,0,map,0);
}