#include<bits/stdc++.h>
using namespace std;

class TreeNode 
{
	public:
	int data;
	vector<TreeNode*> children;

	TreeNode(int data) {
		this->data = data;
	}
};

TreeNode* takeInputLevelWise() 
{
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode* root = new TreeNode(rootData);

	queue<TreeNode*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) 
    {
		TreeNode* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) 
        {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode* child = new TreeNode(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void levelDown(TreeNode* root, int k, TreeNode* blockNode, vector<vector<int>>& ans)
{
    if(k < 0) return;
    if(ans.size() < k + 1) ans.resize(k + 1);
    
    ans[k].push_back(root->data);
    for(TreeNode* child : root->children)
        if(child != blockNode)
            levelDown(child, k + 1, blockNode, ans);
}

int height(TreeNode* root, int data, vector<vector<int>>& ans)
{
    if(root->data == data) 
    {
        levelDown(root, 0, NULL, ans);
        return 1;
    }

    int h = -1;
    TreeNode* blockNode = NULL;
    for(TreeNode* child : root->children)
    {
        h = height(child, data, ans);
        if(h != -1)
        {
            blockNode = child;
            break;
        }
    }
    levelDown(root, h, blockNode, ans);
    return (h != -1) ? 1 + h : -1;
}

int main()
{
    TreeNode* root = takeInputLevelWise();
    vector<vector<int>>ans;
    height(root, 80, ans);
    cout<<"\n***********************\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<i<<"'s: ";
        for(int j = 0; j < ans[i].size(); j++)
        {
            if(j != ans[i].size() - 1) cout<<ans[i][j]<<", ";
            else cout<<ans[i][j]<<"\n";
        }
    }
}
