#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]

Input: [1,2,3,8,null,5,0,null,null,4,null]
Output: [1, 3, 5, 4]
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// level-order traversal
vector<int> rightSideView(TreeNode* root)
{
	if (root == nullptr)
		return vector<int>();

	vector<int> ans;
	queue<TreeNode*> q;

	q.push(root);
	while (q.size() > 0)
	{
		ans.push_back(q.back()->val);
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
	}
	return ans;
}

int main()
{
	int target;
	while (cin >> target)
	{
		int p[] = { 1,2,3,NULL,5,NULL,4 };
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(3);
		root->left->right = new TreeNode(5);
		root->right->right = new TreeNode(4);

		vector<int> nums = rightSideView(root);
		for (auto i : nums)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}