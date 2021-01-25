#include<iostream>
#include <vector>
using namespace std;

/*
Input: root = [3,9,20,null,null,15,7]
Output: 2

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool ans = true;

int findDepth(TreeNode* node)
{
	if (node == nullptr || ans == false)
		return 0;

	int l = findDepth(node->left);
	int r = findDepth(node->right);

	if (abs(l - r) > 1)
	{
		ans = false;
		return 0;
	}

	return max(l, r) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;

	findDepth(root);
	return ans;
}

int main()
{
	/*int intput[] = { 3,9,20,NULL,NULL,15,7 };
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);*/

	int intput[] = { 2,NULL,3,NULL,4,NULL,5,NULL,6 };
	TreeNode* root = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(5);
	root->right->right->right->right = new TreeNode(6);

	cout << isBalanced(root) << "\n";

	return 0;
}