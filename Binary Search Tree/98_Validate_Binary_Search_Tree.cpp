#include<iostream>
#include <vector>
using namespace std;

/*
Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false

Input: root = [0, -1]
Output: true

Input: root = [1, 1]
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

TreeNode* last;

// in-order traversal : left, mid, right
bool isValidBST(TreeNode* root)
{
	if (root == NULL)
		return true;

	if (isValidBST(root->left) == false)
		return false;
	if (last != NULL && root->val <= last->val)
		return false;
	last = root;

	return isValidBST(root->right);
}

int main()
{
	int target;
	while (cin >> target)
	{
		int p[] = { 5,1,4,NULL,NULL,3,6 };
		TreeNode* root = new TreeNode(5);
		root->left = new TreeNode(1);
		root->right = new TreeNode(8);
		root->right->left = new TreeNode(4);
		root->right->right = new TreeNode(10);

		cout << isValidBST(root) << "\n";
	}
	return 0;
}