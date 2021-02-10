//Symmetric Tree
bool isMirror(TreeNode* t1, TreeNode* t2) 
{
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
}
bool isSymmetric(TreeNode* root) 
{
    return isMirror(root,root);
}

//Invert Binary Tree
TreeNode* invertTree(TreeNode* root) 
{
    if(root == NULL) return root;
    
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->right = left;
    root->left = right;
    
    return root;
}
// {or}
TreeNode* invertTree(TreeNode* root) 
{
    if(root == NULL) return root;
    
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    
    return root;
}

//Subtree of Another Tree
bool check(TreeNode* s, TreeNode* t)
{
    if(s == NULL && t == NULL) return true;
    if(s == NULL || t == NULL) return false;
    
    if(s->val != t->val) return false;
    
    return check(s->left, t->left) && check(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) 
{
    if(s == NULL && t == NULL) return true;
    if(s == NULL) return false;
    
    if(s->val == t->val && check(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
