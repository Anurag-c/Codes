int ans = INT_MIN;
int maxBranchSum(TreeNode* root)
{
    if(root == NULL) return 0;
    
    int leftAns = maxBranchSum(root->left);
    int rightAns = maxBranchSum(root->right);
    
    int op1 = max(leftAns, rightAns) + root->val; 
    int op2 = leftAns + root->val + rightAns;
    ans = max(ans, max(max(op1, op2), root->val));
    
    return max(root->val, op1);
}
int maxPathSum(TreeNode* root) 
{
    maxBranchSum(root);
    return ans;
}

