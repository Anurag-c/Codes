 pair<TreeNode*, TreeNode*> pre(TreeNode* root)
{
    if(root == NULL) return {NULL, NULL};
    if(root->left == NULL && root->right == NULL) return {root, root};
    
    pair<TreeNode*, TreeNode*>p = pre(root->left);
    TreeNode* lhead = p.first;
    TreeNode* ltail = p.second;
    
    p = pre(root->right);
    TreeNode* rhead = p.first;
    TreeNode* rtail = p.second;
    
    root->right = lhead;
    root->left = NULL;
    
    if(rhead == NULL) return {root, ltail}; // right subtree empty
    else if(ltail == NULL) ltail = root; // left subtree empty
    
    ltail->right = rhead;
    return {root, rtail};
}

void flatten(TreeNode* root)
{
    pre(root);
}

//other way
TreeNode* pre = NULL;
void flatten(TreeNode* root)
{
    if(root == NULL) return;
    
    TreeNode* temp = root->right;
    
    if(pre)
    {
        pre->right = root;
        pre->left = NULL;
    } 
    pre = root;
    
    flatten(root->left);
    flatten(temp);
}