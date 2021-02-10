Node* connect(Node* root) 
{
    if(root == NULL) return root;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        Node* prev = NULL;
        while(size--)
        {
            Node* curr = q.front();
            q.pop();
            if(prev != NULL) prev->next = curr;
            prev = curr;
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        prev->next = NULL;
    }
    return root;
}