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

vector<vector<int>> printLevelWise(TreeNode* root) 
{
    queue<TreeNode*>q;
    vector<vector<int>>ans;
    vector<int>level;
    q.push(root);
    while(!q.empty())
    {
        level.clear();
        int size = q.size();
        while(size--)
        {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->data);
            for(int i = 0 ; i < curr->children.size(); i++)
                q.push(curr->children[i]);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    TreeNode* root = takeInputLevelWise();
    vector<vector<int>>levels = printLevelWise(root);
    int i = 0;
    int j = levels.size() - 1;
    while(i <= j)
    {
        for(int x = levels[i].size() - 1; x >= 0; x--) cout<<levels[i][x]<<" ";
        if(i != j) for(int x = 0; x < levels[j].size(); x++) cout<<levels[j][x]<<" ";
        i++;
        j--;
    }
}

