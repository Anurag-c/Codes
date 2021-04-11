Node* getRight(Node* next, Node* curr)
{
    while(next->right != NULL && next->right != curr)
        next = next->right;
    
    return next;
}

vector<int> inOrder(Node* root)
{
    vector<int>ans;
    Node* curr = root;
    while(curr != NULL)
    {
        Node* next = curr->left;
        if(next == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            Node* rightMost = getRight(next, curr);
            if(rightMost->right == NULL)
            {
                rightMost->right = curr;
                curr = curr->left;
            }
            else if(rightMost->right == curr)
            {
                ans.push_back(curr->val);
                curr = curr->right;
                rightMost->right = NULL;
            }
        }
    }
    return ans;
}

vector<int> preOrder(Node* root)
{
    vector<int>ans;
    Node* curr = root;
    while(curr != NULL)
    {
        Node* next = curr->left;
        if(next == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            Node* rightMost = getRight(next, curr);
            if(rightMost->right == NULL)
            {
                ans.push_back(curr->val);
                rightMost->right = curr;
                curr = curr->left;
            }
            else if(rightMost->right == curr)
            {
                curr = curr->right;
                rightMost->right = NULL;
            }
        }
    }
    return ans;
}