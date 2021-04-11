pair<Node*,Node*> getHeadTail(Node* root)
{
    if(root == NULL) return {NULL, NULL};
    if(root->left == NULL and root->right == NULL) return {root, root};
    
    pair<Node*,Node*>p = getHeadTail(root->left);
    Node* Lhead = p.first;
    Node* Ltail = p.second;
    
    p = getHeadTail(root->right);
    Node* Rhead = p.first;
    Node* Rtail = p.second;
    
    root->left = Ltail;
    if(Ltail != NULL) Ltail->right = root;
    root->right = Rhead;
    if(Rhead != NULL) Rhead->left = root;
    
    Node* head = (Lhead) ? Lhead : root;
    Node* tail = (Rtail) ? Rtail : root;
    return {head, tail};
}

Node* treeToDoublyList(Node* root) 
{
    if(root == NULL) return NULL;
    
    pair<Node*,Node*>p = getHeadTail(root);
    Node* head = p.first;
    Node* tail = p.second;
    
    tail->right = head;
    head->left = tail;
    
    return head;
}