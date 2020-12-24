
bool isPossible(vector<int> &piles, int h, int k)
{
    int time = 0;
    for(int p : piles)
    {
        time += ceil((float)p/k); 
        // if you do p/k we get integer better p/(k * 1.0) or (float)p / k
        if(time > h) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int H) 
{
    int minSpeed = 1;
    int maxSpeed = *max_element(piles.begin(),piles.end());
    while(minSpeed < maxSpeed)
    {
        int currSpeed = (minSpeed + maxSpeed)/2;
        if(isPossible(piles,H,currSpeed)) maxSpeed = currSpeed;
        else minSpeed = currSpeed + 1;
    }
    return minSpeed; 
    // we can also return maxSpeed because the loop breaks when minSpeed == maxSpeed
}