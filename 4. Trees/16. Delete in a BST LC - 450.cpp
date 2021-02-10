
TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(root == NULL) return root;
    
    if(key < root->val)
        root->left = deleteNode(root->left, key);
    else if(key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->right == NULL || root->left == NULL)
            return (root->left != NULL) ? root->left : root->right;
        
        else
        {
            TreeNode* temp = root->left;
            while(temp->right != NULL)
                temp = temp->right;
            
            root->val = temp->val;
            root->left = deleteNode(root->left, root->val);
        }
    }
    return root;
}

