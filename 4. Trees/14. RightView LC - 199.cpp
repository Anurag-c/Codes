vector<int> rightSideView(TreeNode* root) 
{
    vector<int>ans;
    if(root == NULL) return ans;
    
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        TreeNode* leftmost = q.front();
        ans.push_back(leftmost->val);
        while(size--)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }
    }
    return ans;
}

//recursion
int maxLevel = INT_MIN;
vector<int>ans;
void rightView(TreeNode* root, int level)
{
    if(root == NULL) return;
    
    if(level > maxLevel)
    {
        maxLevel = level;
        ans.push_back(root->val);
    }
    rightView(root->right,level + 1);
    rightView(root->left, level + 1);
}

vector<int> rightSideView(TreeNode* root) 
{
    rightView(root,0);
    return ans;
}