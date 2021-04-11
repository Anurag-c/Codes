class Info
{
    public:
    Node* curr;
    bool selfDone,leftDone,rightDone;
    Info(Node* curr, bool self, bool left, bool right)
    {
        this->curr = curr;
        selfDone = self;
        leftDone = left;
        rightDone = right;
    }
};

vector<int> inOrder(Node* root)
{
    if(root == NULL) return {};
    
    vector<int>ans;
    stack<Info*>st;
    st.push(new Info(root, false, false, false));
    while(!st.empty())
    {
        Info* temp = st.top();
        if(!temp->leftDone)
        {
            temp->leftDone = true;
            if(temp->curr->left != NULL) 
                st.push(new Info(temp->curr->left, false, false, false));
        }
        else if(!temp->selfDone)
        {
            temp->selfDone = true;
            ans.push_back(temp->curr->data);
        }
        else if(!temp->rightDone)
        {
            temp->rightDone = true;
            if(temp->curr->right != NULL) 
                st.push(new Info(temp->curr->right, false, false, false));
        }
        else st.pop();
    }
    return ans;
}