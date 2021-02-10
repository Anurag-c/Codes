bool hasPathSum(TreeNode* root, int targetSum) 
{
    if(root == NULL) return false;
    
    targetSum -= root->val;
    if(root->left == NULL && root->right == NULL) 
        return (targetSum == 0);
    
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

vector<vector<int>>paths;
vector<int>currPath;

void getPaths(TreeNode* root, int targetSum)
{
    if(root == NULL) return;
    
    targetSum -= root->val;
    currPath.push_back(root->val);
    
    if(root->left == NULL && root->right == NULL && targetSum == 0)
        paths.push_back(currPath);
    
    else
    {
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }
   
    currPath.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    getPaths(root, targetSum);
    return paths;
}