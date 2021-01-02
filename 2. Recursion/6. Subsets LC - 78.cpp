
vector<vector<int>>subset;
void generate(vector<int>& arr, int idx, vector<int>& curr)
{
    if(idx == arr.size())
    {
        subset.push_back(curr);
        return;
    }
    generate(arr, idx + 1, curr); // dont consider
    curr.push_back(arr[idx]); // conisder
    generate(arr, idx + 1, curr);
    curr.pop_back(); // backtrack as this is passed as reference
}