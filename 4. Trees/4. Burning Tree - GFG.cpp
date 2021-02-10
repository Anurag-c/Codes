int height(Node* root)
{
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int nodeAtDistance(Node* root, int target, int& ans)
{
    if(root == NULL) return -1;
    if(root->data == target) return 1;
    
    int ld = nodeAtDistance(root->left, target, ans);
    if(ld != -1)
    {
        ans = max(ans, ld + height(root->right));
        return ld + 1;
    }
    int rd = nodeAtDistance(root->right, target, ans);
    if(rd != -1)
    {
        ans = max(ans, rd + height(root->left));
        return rd + 1;
    }
    return -1;
}

int minTime(Node* root, int target) 
{
    int ans = 0;
    nodeAtDistance(root, target, ans);
    return ans;
}


