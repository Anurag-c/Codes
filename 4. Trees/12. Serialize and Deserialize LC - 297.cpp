vector<string> split(string data)
{
    vector<string>ans;
    string curr;
    for(int i = 0; i < data.length(); i++)
    {
        if(data[i] == ',') 
        {
            ans.push_back(curr);
            curr.erase();
        }
        else curr.push_back(data[i]);
    }
    return ans;
}

string serialize(TreeNode* root) 
{
    if(root == NULL) return "N,";
    
    string encode;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
        
        if(curr == NULL) 
        {
            encode.append("N,");
            continue;
        }
        else encode.append(to_string(curr->val) + ",");
        
        if(curr->left == NULL) q.push(NULL);
        else q.push(curr->left);
        
        if(curr->right == NULL) q.push(NULL);
        else q.push(curr->right);
    }
    return encode;
}



TreeNode* deserialize(string data) 
{
    vector<string>s = split(data);
    if(s[0] == "N") return NULL;
    
    int n = s.size();
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(stoi(s[0]));
    q.push(root);
    
    int leftIdx = 1;
    int rightIdx = 2;
    while(!q.empty())
    {
        TreeNode* curr = q.front();
        q.pop();
    
        if(leftIdx < n && s[leftIdx] != "N")
        {
            curr->left = new TreeNode(stoi(s[leftIdx]));
            q.push(curr->left);
        }
        if(rightIdx < n && s[rightIdx] != "N")
        {
            curr->right = new TreeNode(stoi(s[rightIdx]));
            q.push(curr->right);
        }
        leftIdx += 2;
        rightIdx += 2;
    }
    return root;
}