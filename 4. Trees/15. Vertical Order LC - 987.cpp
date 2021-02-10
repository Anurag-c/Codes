vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    unordered_map<int, vector<int>>hm;
    int minScale = INT_MAX;
    int maxScale = INT_MIN;
    
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    vector<pair<int,int>>currlevel;
    
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            pair<TreeNode*, int>p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int scale = p.second;
            minScale = min(minScale, scale);
            maxScale = max(maxScale, scale);
            
            currlevel.push_back({curr->val, scale});
            if(curr->left) q.push({curr->left, scale - 1});
            if(curr->right) q.push({curr->right, scale + 1});
        }
        sort(currlevel.begin(), currlevel.end());
        for(auto p : currlevel)
            hm[p.second].push_back(p.first);
        currlevel.clear();
    }
    
    vector<vector<int>>ans;
    for(int i = minScale; i <= maxScale; i++)
        ans.push_back(hm[i]); 
    
    return ans;   
}

//by Width
void width(TreeNode* root, int scale, int& lend, int& rend)
{
    if(root == NULL) return;

    lend = min(lend,scale);
    rend = max(rend,scale);
    width(root->left, scale - 1, lend, rend);
    width(root->right, scale + 1, lend, rend);
}

vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    int lend = INT_MAX;
    int rend = INT_MIN;
    width(root, 0, lend, rend);
    int size = rend - lend + 1;
    vector<vector<int>>hm(size);
    
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});
    vector<pair<int,int>>currlevel;
    
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            pair<TreeNode*, int>p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int scale = p.second;
            
            currlevel.push_back({curr->val, scale});
            if(curr->left) q.push({curr->left, scale - 1});
            if(curr->right) q.push({curr->right, scale + 1});
        }
        sort(currlevel.begin(), currlevel.end());
        for(auto p : currlevel)
            hm[p.second - lend].push_back(p.first);
        currlevel.clear();
    }
    
    vector<vector<int>>ans;
    for(int i = 0; i < size; i++)
        ans.push_back(hm[i]); 
    
    return ans;   
}

//by priority_queue
struct comp
{
    bool operator()(pair< TreeNode*, pair<int,int>>& a, pair< TreeNode*, pair<int,int>>& b)
    {
        if(a.second.second == b.second.second)
        return a.first->val > b.first->val;

        return a.second.second > b.second.second;
    }
};

vector<vector<int>> verticalTraversal(TreeNode* root) 
{
    int lend = INT_MAX;
    int rend = INT_MIN;
    width(root, 0, lend, rend);
    int size = rend - lend + 1;
    vector<vector<int>>hm(size);
    
    priority_queue< pair< TreeNode*, pair<int,int> >, vector< pair< TreeNode*, pair<int,int> > >, comp>q;
    
    q.push({root, {0,0}});
    
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            pair< TreeNode*, pair<int,int> >p = q.top();
            q.pop();
            
            TreeNode* curr = p.first;
            pair<int,int>xy = p.second;
            int scale = xy.first;
            int level = xy.second;
            
            hm[scale - lend].push_back(p.first->val);
            if(curr->left) q.push({curr->left, {scale - 1, level + 1}});
            if(curr->right) q.push({curr->right, {scale + 1, level + 1}});
        }
    }
    
    vector<vector<int>>ans;
    for(int i = 0; i < size; i++)
        ans.push_back(hm[i]); 
    
    return ans;   
}




