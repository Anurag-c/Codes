
class TimeMap {

    public:
    unordered_map<string, vector<pair<int, string>> >hm;
    
    void set(string key, string value, int timestamp) 
    {
        hm[key].push_back(make_pair(timestamp, value));
    }
    
    int pos(vector<pair<int, string>> &arr, int timestamp)
    {
        int start = 0,end = arr.size() -1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(arr[mid].first == timestamp) return mid;
            else if(arr[mid].first < timestamp) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
    string get(string key, int timestamp) 
    {
        int idx = pos(hm[key], timestamp);
        if(idx < 0) return "";
        return hm[key][idx].second;
    }
};
