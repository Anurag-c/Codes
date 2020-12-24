
bool isvalid(vector<int>& weights,int D,int mid)
{
	int total = 0, days = 1;
	for(int i=0; i < weights.size(); i++)
	{
		total += weights[i];
		if(total > mid)
		{
			days++;
			total = weights[i];
		}
	}
	return days <= D;
}
int shipWithinDays(vector<int>& weights, int D) 
{
	int low = INT_MIN, high = 0;
	for(int i = 0; i < weights.size(); i++)
	{
		low = max(weights[i], low);
		high += weights[i];
    }
	while(low < high)
	{
		int mid = low + (high - low)/2;
		if(isvalid(weights, D, mid)) high = mid;
		else low = mid + 1;
	}
	return low;
}



