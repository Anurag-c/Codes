vector<int>ans;
void getLeft(TreeNode* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    
    ans.push_back(root->val);
    if(root->left != NULL) getLeft(root->left);
    else getLeft(root->right);
}
void getRight(TreeNode* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    
    if(root->right != NULL) getRight(root->right);
    else getRight(root->left);
    ans.push_back(root->val);
}
void getLeafs(TreeNode* root)
{
    if(root == NULL) return;
    if(root->right == NULL && root->left == NULL)
    {
        ans.push_back(root->val);
        return;
    }
    getLeafs(root->left);
    getLeafs(root->right);
}

vector<int> boundaryOfBinaryTree(TreeNode* root) 
{
    if(root == NULL) return ans;
    
    ans.push_back(root->val);
    if(root->left == NULL && root->right == NULL) return ans;
    
    getLeft(root->left);
    getLeafs(root);
    getRight(root->right);
    
    return ans;
}