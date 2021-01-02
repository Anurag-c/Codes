
//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
int majorityElement(vector<int>& arr) 
{
    int n = arr.size();
    int major_element = arr[0];
    int count = 1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == major_element) count++;
        else
        {
            count--;
            if(count == 0)
            {
                major_element = arr[i];
                count = 1;
            }
        }
    }
    // Check Major or Not
    count = 0;
    for(int i = 0; i < n; i++) 
        if(arr[i] == major_element) count++;
    return (count > n/2) ? major_element : -1;
}

// n / 3
vector<int> majorityElement(vector<int>& arr) 
{
    int n = arr.size();
    if(n == 0) return {};
    if(n == 1) return {arr[0]};
    
    int m1 = arr[0], m2 = arr[1];
    int c1 = 0, c2 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == m1) c1++;
        else if(arr[i] == m2) c2++;
        else if(c1 == 0)
        {
            m1 = arr[i];
            c1 = 1;
        }
        else if(c2 == 0)
        {
             m2 = arr[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    
    c1 = c2 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == m1) c1++;
        else if(arr[i] == m2) c2++;
    }
    vector<int>ans;
    if(c1 > n/3) ans.push_back(m1);
    if(c2 > n/3) ans.push_back(m2);
    return ans;
}


