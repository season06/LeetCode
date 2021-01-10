#include<iostream>
#include <vector>
using namespace std;

/*
Input: tree = [1,2,2,3,4,4,3]
Output: true

Input: tree = [1,2,2,3,4,4,3,5,6,7,8,8,7,6,5]
Output: true

Input: tree = [1,2,2,null,3,null,3]
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
bool isSame(TreeNode* l, TreeNode* r)
{
	if (l == NULL && r == NULL)
		return true;
	if (l == NULL || r == NULL)
		return false;
	if (l->val != r->val)
		return false;
	return isSame(l->left, r->right) && isSame(l->right, r->left); // left, right is mirror
}
bool isSymmetric(TreeNode* root)
{
	if (root == NULL)
		return true;
	return isSame(root->left, root->right);
}

int main()
{
	int target;
	while (cin >> target)
	{
		int p[] = { 1,2,2,3,4,4,3 };
		TreeNode* root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->right = new TreeNode(2);
		root->left->left = new TreeNode(5);
		root->left->right = new TreeNode(4);
		root->right->left = new TreeNode(4);
		root->right->right = new TreeNode(3);

		cout << isSymmetric(root) << "\n";
	}
	return 0;
}