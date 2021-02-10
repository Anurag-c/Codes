int paths = 0;
void pathSum2(TreeNode* root, int sum, int currSum, unordered_map<int,int>& hm) 
{
    if(root == NULL) return;
    
    currSum += root->val;
    if(hm.find(currSum - sum) != hm.end()) paths += hm[currSum - sum];
    
    hm[currSum]++;
    pathSum2(root->left, sum, currSum, hm);
    pathSum2(root->right, sum, currSum, hm);
    hm[currSum]--;
}
int pathSum(TreeNode* root, int sum) 
{
    if(root == NULL) return 0;
    
    unordered_map<int,int>hm;
    hm[0] = 1;
    pathSum2(root, sum, 0, hm);
    return paths;
}