
vector<TreeNode*> generateTrees(int start, int end)
{
    vector<TreeNode*>ans;
    if(start > end)
    {
        ans.push_back(NULL);
        return ans;
    }
    
    for(int i = start; i <= end; i++)
    {
        vector<TreeNode*>left_trees = generateTrees(start, i - 1);
        vector<TreeNode*>right_trees = generateTrees(i + 1, end);
        
        for(auto l : left_trees)
        {
            for(auto r : right_trees)
            {
                TreeNode* current = new TreeNode(i);
                current->left = l;
                current->right = r;
                ans.push_back(current);
            }
        }
    }
    return ans;
}




