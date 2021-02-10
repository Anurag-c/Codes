class Info
{
    public :
    int maxSum_NC;
    int maxSum_C;
    
    Info()
    {
        maxSum_NC = 0;
        maxSum_C = 0;
    }
};

class Solution 
{
    public:
    Info maxSum(TreeNode* root)
    {
        Info current;
        if(root == NULL) return current;
        
        Info left = maxSum(root->left);
        Info right = maxSum(root->right);
        
        current.maxSum_C = left.maxSum_NC + root->val + right.maxSum_NC;
        current.maxSum_NC = max(left.maxSum_C, left.maxSum_NC) + max(right.maxSum_C, right.maxSum_NC);
        
        return current;
    }
    int rob(TreeNode* root) 
    {
        Info ans = maxSum(root);
        return  max(ans.maxSum_C, ans.maxSum_NC);
    }
};