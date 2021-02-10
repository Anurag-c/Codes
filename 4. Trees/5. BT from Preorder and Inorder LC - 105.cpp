
int idx = 0;
TreeNode* build(vector<int>& pre, vector<int>& in, int low, int high)
{
    if(idx >= pre.size()) return NULL;
    if(low > high) return NULL
    for(int i = low; i <= high ; i++)
    {
        if(pre[idx] == in[i])
        {
            pos = i;
            break;
        }
    }
    idx++;
    TreeNode* root = new TreeNode(in[pos]);
    root->left = build(pre, in, low, pos - 1);
    root->right = build(pre, in, pos + 1, high);
    return root; 
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    return build(preorder, inorder, 0, preorder.size() - 1);   
}

//{or}
int idx = 0;
TreeNode* build(vector<int>& pre, unordered_map<int, int>& hm, int low, int high)
{
    if(low > high) return NULL;
    
    int pos = hm[pre[idx]];
    TreeNode* root = new TreeNode(pre[idx]);
    
    idx++;
    root->left = build(pre, hm, low, pos - 1);
    root->right = build(pre, hm, pos + 1, high);
    return root; 
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    unordered_map<int, int>hm;
    for(int i = 0; i < inorder.size(); i++)
        hm[inorder[i]] = i;
    
    return build(preorder, hm, 0, preorder.size() - 1);   
}