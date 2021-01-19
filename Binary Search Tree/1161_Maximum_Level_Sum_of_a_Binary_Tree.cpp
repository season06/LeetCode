#include<iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Input: root = [1,7,0,7,-8,null,null]
Output: 2

Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
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
// BFS
int maxLevelSum(TreeNode* root)
{
	int max = INT_MIN, level = 0;
	int now_level = 1;

	queue<TreeNode*> q;
	q.push(root);
	while (q.size() > 0)
	{
		int sum = 0, size = q.size();
		for (int i = 0; i < size; i++)
		{
			TreeNode* node = q.front(); // get value from queue
			q.pop(); // remove from head of queue.

			sum += node->val;
			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		if (sum > max)
		{
			max = sum;
			level = now_level;
		}
		now_level++;
	}
	return level;
}

int main()
{
	int target;
	while (cin >> target)
	{
		int p[] = { 989,NULL,10250,98693,-89388,NULL,NULL,NULL,-32127 };
		TreeNode* root = new TreeNode(989);
		root->right = new TreeNode(10250);
		root->right->left = new TreeNode(98693);
		root->right->right = new TreeNode(-89388);
		root->right->right->right = new TreeNode(-32127);

		cout << maxLevelSum(root) << "\n";
	}
	return 0;
}