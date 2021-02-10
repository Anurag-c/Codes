#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
    public :
    int val, h, bal;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
        h = bal = 0;
    }
};

void display(TreeNode* root)
{
    if(root == NULL) return;
    cout<<root->val<<" "<<root->h<<" "<<root->bal<<"\n";
}

void inorder(TreeNode* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


void upadateHAndBal(TreeNode* root)
{
    if(root == NULL) return;

    int lh = -1;
    int rh = -1;

    if(root->left != NULL) lh = root->left->h;
    if(root->right != NULL) rh = root->right->h;

    root->h = max(lh, rh) + 1;
    root->bal = lh - rh;
} 

TreeNode* rightRotation(TreeNode* A)
{
    TreeNode* B = A->left;
    TreeNode* BkaRight = B->right;

    B->right = A;
    A->left = BkaRight;

    upadateHAndBal(A); // We can also say getRotation it also does the same as its 1st line is updating
    upadateHAndBal(B); // after upadating A only we update B

    return B; // after rotation B becomes the root;
}

TreeNode* leftRotation(TreeNode* A)
{
    TreeNode* B = A->right;
    TreeNode* BkaLeft = B->left;

    B->left = A;
    A->right = BkaLeft;

    upadateHAndBal(A); 
    upadateHAndBal(B); 

    return B; 
}

TreeNode* getRotation(TreeNode* root)
{
    if(root == NULL) return root;

    upadateHAndBal(root);
    if(root->bal == 2) // LL, LR
    {
        if(root->left->bal == 1) // LL
            return rightRotation(root);
        else // LR
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if(root->bal == -2) // RR, RL
    {
        if(root->right->bal == -1) // RR
            return leftRotation(root);
        else // RL
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    return root;
}


TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root == NULL)
        return new TreeNode(val);
    
    if(val < root->val)
        root->left = insertIntoBST(root->left, val);
    else if(val > root->val)
        root->right = insertIntoBST(root->right, val);

    root = getRotation(root);
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(root == NULL) return root;
    
    if(key < root->val)
        root->left = deleteNode(root->left, key);
    else if(key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->right == NULL || root->left == NULL)
            root = (root->left != NULL) ? root->left : root->right;
        
        else
        {
            TreeNode* temp = root->left;
            while(temp->right != NULL)
                temp = temp->right;
            
            root->val = temp->val;
            root->left = deleteNode(root->left, root->val);
        }
    }
    return getRotation(root);
}


int main()
{
    TreeNode* root = NULL;
    for(int i = 1; i <= 10; i++)
    {
        root = insertIntoBST(root, i);
        display(root);
    }
    display(root);
    inorder(root);
}