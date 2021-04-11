TreeNode* bstFromPreorder(vector<int>& pre) 
{
    int n = pre.size();
    if(n == 0) return NULL;
    
    stack<TreeNode*>st;
    TreeNode* root = new TreeNode(pre[0]);
    st.push(root);
    
    for(int i = 1; i < n; i++)
    {
        TreeNode* curr = st.top();
        while(!st.empty() && pre[i] > st.top()->val)
        {
            curr = st.top();
            st.pop();
        }
        
        TreeNode* node = new TreeNode(pre[i]);
        if(pre[i] > curr->val) curr->right = node;
        else curr->left = node;
    
        st.push(node);
    }
    return root;
}

bool canRepresentBST(int pre[], int n) 
{ 
    stack<int>s; 
    int root = INT_MIN; 

    for(int i = 0; i < n; i++) 
    { 
        if (pre[i] < root) return false; 
        while (!s.empty() &&  pre[i] > s.top()) 
        { 
            root = s.top(); 
            s.pop(); 
        } 
        s.push(pre[i]); 
    } 
    return true; 
} 

// works only when no duplicates
int bst_idx = 0;
TreeNode* construct(vector<int>& pre, int l, int r)
{
    if(bst_idx >= pre.size() || pre[bst_idx] < l || pre[bst_idx] > r) 
        return NULL;
    
    TreeNode* curr = new TreeNode(pre[bst_idx++]);
    curr->left = construct(pre, l, curr->val);
    curr->right = construct(pre, curr->val, r);
    return curr;
}

TreeNode* bstFromPreorder(vector<int>& pre) 
{
    int n = pre.size();
    if(n == 0) return NULL;
    return construct(pre, INT_MIN, INT_MAX);   
}