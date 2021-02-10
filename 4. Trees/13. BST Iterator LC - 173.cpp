class BSTIterator {
public:
    
    stack<TreeNode*>st;
    
    void addLeft(TreeNode* curr)
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
    }
    
    BSTIterator(TreeNode* root) 
    {
        addLeft(root);
    }
    
    int next() 
    {
        TreeNode* ans = st.top();
        st.pop();
        
        if(ans->right != NULL) addLeft(ans->right);
        return ans->val;
    }
    
    bool hasNext() 
    {
        return (!st.empty());
    }
};
