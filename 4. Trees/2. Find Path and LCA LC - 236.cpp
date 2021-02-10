void findPath(TreeNode* root , TreeNode* x , vector<TreeNode*> &path)
{
    if(root == NULL) return;
    if(root == x)
    {
        path.push_back(root);
        return;
    }
    findPath(root->left, x, path);
    if(path.size() != 0)
    {
        path.push_back(root);
        return;
    }
    findPath(root->right, x, path);
    if(path.size() != 0)
    {
        path.push_back(root);
        return;
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if(root == NULL) return root;
    
    vector<TreeNode*>p1,p2;
    findPath(root, p, p1);
    findPath(root, q, p2);
    
    int i = p1.size() - 1, j = p2.size() - 1;
    TreeNode* LCA = NULL;
    while(i >= 0 && j >= 0)
    {
        if(p1[i] == p2[j])
        {
            LCA = p1[i];
            i--;
            j--;
        }
        else break;
    }
    return LCA;
}

