
void nodesAtLevelK(TreeNode* root, int level, vector<int>& ans)
{
    if(root == NULL) return;
    if(level == 0)
    {
        ans.push_back(root->val);
        return;
    }
    nodesAtLevelK(root->left, level - 1, ans);
    nodesAtLevelK(root->right, level - 1, ans);
}

int find(TreeNode* root, TreeNode* target, int K, vector<int>& ans)
{
    if(root == NULL) return -1;
    if(root == target)
    {
        nodesAtLevelK(root, K, ans);
        return 1;
    } 
    
    int ld = find(root->left, target, K, ans);
    if(ld != -1 && ld <= K)
    {
        if(ld == K) ans.push_back(root->val);
        else nodesAtLevelK(root->right, K - ld - 1, ans);
        return ld + 1;
    }
    
    int rd = find(root->right, target, K, ans);
    if(rd != -1 && rd <= K)
    {
        if(rd == K) ans.push_back(root->val);
        else nodesAtLevelK(root->left, K - rd - 1, ans);
        return rd + 1;
    }
    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
{
    vector<int>ans;
    find(root, target, K, ans);
    return ans;
}