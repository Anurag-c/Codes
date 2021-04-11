vector<TreeNode*>forest;
    
TreeNode* del(TreeNode* root, unordered_set<int>& hm)
{
    if(root == NULL) return root;
    
    root->left = del(root->left, hm);
    root->right = del(root->right, hm);
    
    if(hm.find(root->val) != hm.end())
    {
        if(root->left) forest.push_back(root->left);
        if(root->right) forest.push_back(root->right);
        return NULL;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
{
    if(root == NULL) return {};
    
    unordered_set<int>hm;
    for(int i : to_delete) hm.insert(i);
    root = del(root, hm);
    if(root) forest.push_back(root);
    return forest;
}