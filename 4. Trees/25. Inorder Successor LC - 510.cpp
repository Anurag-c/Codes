Node* inorderSuccessor(Node* node) 
{
    if(node == NULL) return node;
    
    if(node->right)
    {
        node = node->right;
        while(node->left) node = node->left;
        return node;
    }
    while(node->parent)
    {
        Node* temp = node->parent;
        if(temp->left == node) break;   
        node = node->parent;
    }
    return node->parent;
}