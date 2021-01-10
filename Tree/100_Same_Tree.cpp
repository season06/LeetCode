#include<iostream>
#include <vector>
using namespace std;

/*
Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Pre-order Traversal: root, left, right
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (p->val != q->val)
		return false;

	bool is_left = isSameTree(p->left, q->left);
	bool is_right = isSameTree(p->right, q->right);
	return is_left && is_right;
}

int main()
{
	int target;
	while (cin >> target)
	{
		int p[] = { 1,2,3 }, q[] = { 1,2,3 };
		TreeNode* p_tree = new TreeNode(1);
		p_tree->left = new TreeNode(2);
		p_tree->right = new TreeNode(3);
		TreeNode* q_tree = new TreeNode(1);
		q_tree->left = new TreeNode(2);
		q_tree->right = new TreeNode(3);

		cout << isSameTree(p_tree, q_tree) << "\n";
	}
	return 0;
}