TreeNode* prev = NULL;
TreeNode* a = NULL;
TreeNode* b = NULL;

bool solve(TreeNode* curr)
{
    if(curr == NULL) return false;
    if(solve(curr->left)) return true;
    
    if(prev != NULL && prev->val > curr->val)
    {
        b = curr;
        if(a == NULL) a = prev;
        else return true;
    }
    prev = curr;
    return solve(curr->right);
}

void recoverTree(TreeNode* root) 
{
    solve(root);
    int x = a->val;
    a->val = b->val;
    b->val = x;
}