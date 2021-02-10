// Link : https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
// using pair
pair<int, int> maxPathSum2(Node* root)
{     
    if(root == NULL) return {INT_MIN, INT_MIN};
    if(root->left == NULL && root->right == NULL)
    return {root->data, INT_MIN};
    
    pair<int, int> leftMax = maxPathSum2(root->left);
    pair<int, int> rightMax = maxPathSum2(root->right);
    pair<int, int> ans;
    
    ans.first = max(leftMax.first, rightMax.first) + root->data;
    ans.second = max(leftMax.second, rightMax.second);
    
    if(leftMax.first != INT_MIN && rightMax.first != INT_MIN)
    {
        int around = leftMax.first+ root->data + rightMax.first;
        ans.second = max(ans.second, around);
    }
    return ans;
}

int maxPathSum(Node* root)
{ 
    pair<int, int> ans = maxPathSum2(root);
    return ans.second;
}

// Using Global 
int res = INT_MIN;
int maxRTL(Node* root)
{
    if(root == NULL) return INT_MIN;
    
    if(root->left == NULL && root->right == NULL)
        return root->data;
        
    int lrl = maxRTL(root->left);
    int rrl = maxRTL(root->right);
    
    if(lrl != INT_MIN && rrl != INT_MIN) res = max(res, lrl + root->data + rrl);
    return root->data + max(lrl, rrl);
}
int maxPathSum(Node* root)
{ 
    res = INT_MIN;
    maxRTL(root);
    return res;
}

