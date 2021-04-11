int height(TreeNode* root)
{
    if(root == NULL) return -1;
    return max(height(root->right), height(root->left)) + 1;
} 

int getbal(TreeNode* root)
{
    if(root == NULL) return -1;
    return height(root->left) - height(root->right);
}

TreeNode* rightRotation(TreeNode* A)
{
    TreeNode* B = A->left;
    TreeNode* BkaRight = B->right;

    A->left = BkaRight;
    B->right = getRotation(A);
    return getRotation(B);
}

TreeNode* leftRotation(TreeNode* A)
{
    TreeNode* B = A->right;
    TreeNode* BkaLeft = B->left;

    A->right = BkaLeft;
    B->left = getRotation(A);
    return getRotation(B);
}

TreeNode* getRotation(TreeNode* root)
{
    if(root == NULL) return root;

    int bal = getbal(root);
    if(bal >= 2)
    {
        if(getbal(root->left) >= 1)
            return rightRotation(root);
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if(bal <= -2)
    {
        if(getbal(root->right) <= -1)
            return leftRotation(root);
        else
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}

TreeNode* balanceBST(TreeNode* root) 
{
    if(root == NULL) return root;
    
    root->left = balanceBST(root->left);
    root->right = balanceBST(root->right);
    return getRotation(root);
}