Node* constructBst(int arr[], int n)
{
    int idx = 0;
    queue<Info*>q;
    Node* root = new Node(arr[idx++]);
    q.push(new Info(root, INT_MIN, root->data, 0));
    q.push(new Info(root, root->data, INT_MAX, 1));
    
    while(idx < n && !q.empty())
    {
        Info* temp = q.front();
        q.pop();
        if(arr[idx] < temp->lr || arr[idx] > temp->rr) continue;
        
        else if(arr[idx] >= temp->lr && arr[idx] <= temp->rr)
        {
            Node* ne = new Node(arr[idx++]);
            if(temp->dir == 0)
            {
                temp->curr->left = ne;
                q.push(new Info(ne, temp->lr, ne->data, 0));
                q.push(new Info(ne, ne->data, temp->rr, 1));
            } 
            else
            {
                temp->curr->right = ne;
                q.push(new Info(ne, temp->lr, ne->data, 0));
                q.push(new Info(ne, ne->data, temp->rr, 1));
            }
        }
    }
    return root;
}