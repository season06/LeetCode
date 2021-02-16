#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: root = [1,null,2,3]
Output: [1,3,2]

Input: root = [1,2]
Output: [2,1]

Input: root = [1,null,2]
Output: [1,2]
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// In-order Traversal: left, root, right
// recursive
void inorder(TreeNode* node, vector<int>& ans)
{
	if (node == nullptr)
		return;

	inorder(node->left, ans);
	ans.push_back(node->val);
	inorder(node->right, ans);

	return;
}
vector<int> inorderTraversal_(TreeNode* root)
{
	if (root == NULL)
		return vector<int>();

	vector<int> ans;
	inorder(root, ans);

	return ans;
}

// iteration
vector<int> inorderTraversal(TreeNode* root)
{
	if (root == NULL)
		return vector<int>();

	vector<int> ans;
	vector<TreeNode*> stack;
	TreeNode* node = root;
	while (node != NULL || !stack.empty())
	{
		while (node != nullptr)
		{
			stack.push_back(node);
			node = node->left;
		}
		node = stack.back();
		stack.pop_back();
		ans.push_back(node->val);
		node = node->right;
	}
	return ans;
}

int main()
{
	int p[] = { 1,NULL,2,3 };
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	vector<int> ans = inorderTraversal(root);
	for (auto i : ans)
		cout << i << " ";

	system("pause");
	return 0;
}