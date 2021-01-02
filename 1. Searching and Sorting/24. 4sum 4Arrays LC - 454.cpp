
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
{
    unordered_map<int,int>hm;
    int a = A.size();
    int b = B.size();
    int c = C.size();
    int d = D.size();
    
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++) hm[A[i] + B[j]]++;
    }
    int ans = 0;
    for(int k = 0; k < c; k++)
    {
        for(int l = 0; l < d; l++) 
        {
            int sum = -(C[k] + D[l]);
            if(hm.find(sum) != hm.end()) ans += hm[sum];
        }
    }
    return ans;
}

// ksum

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    return kSumCount(vector<vector<int>>() = {A, B, C, D});
}
int kSumCount(vector<vector<int>> &lists) {
    unordered_map<int, int> m;
    addToHash(lists, m, 0, 0);
    return countComplements(lists, m, lists.size() / 2, 0);
}
void addToHash(vector<vector<int>> &lists, unordered_map<int, int> &m, int i, int sum) {
    if (i == lists.size() / 2)
        ++m[sum];
    else
        for (int a : lists[i])
            addToHash(lists, m, i + 1, sum + a);
}
int countComplements(vector<vector<int>> &lists, unordered_map<int, int> &m, int i, int complement) {
    if (i == lists.size()) {
        auto it = m.find(complement);
        return it == end(m) ? 0 : it->second;
    }
    int cnt = 0;
    for (int a : lists[i])
        cnt += countComplements(lists, m, i + 1, complement - a);
    return cnt;
}