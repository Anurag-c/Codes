#include<bits/stdc++.h>
using namespace std;

// 1. Combinations
int placeQueens_C(int idx, int boxes, int queens, string ans)
{
    if(queens == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }
    int c = 0;
    for(int i = idx ; i < boxes ; i++) 
        c += placeQueens_C(i + 1, boxes, queens - 1, ans + to_string(i) + " ");

    return c;
}

// 2. Permutations
int placeQueens_P(int boxes, int queens, vector<bool> &vis, string ans)
{
    if(queens == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }
    int c = 0;
    for(int i = 0 ; i < boxes ; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            c += placeQueens_P(boxes, queens - 1, vis, ans + to_string(i) + " ");
            vis[i] = false;
        }
    }
    return c;
}

int main()
{
    cout<<placeQueens_C(0, 5, 3, "")<<"\n";
    vector<bool>vis(5,false);
    cout<<placeQueens_P(5, 3, vis, "")<<"\n";
}
    