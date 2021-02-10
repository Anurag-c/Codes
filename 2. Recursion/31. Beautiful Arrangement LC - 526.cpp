int solve(int idx, int vis, int n)
{
    if(idx > n) return 1;
    
    int c = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!(vis & (1 << i)) && ((i % idx) == 0 || (idx % i) == 0) )
        {
            vis ^= (1<<i);
            c += solve(idx + 1, vis, n);
            vis ^= (1<<i);
        }
    }
    return c;
}

int countArrangement(int n) 
{
    return solve(1, 0, n);
}