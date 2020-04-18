#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct ListNode {
	char val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
};

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode *now1 = l1, *now2 = l2;
	ListNode *ans = new ListNode(-1);
	ListNode *current = ans;
	int carry = 0;
	while (now1 != NULL || now2 != NULL)
	{
		int x = (now1 != NULL) ? now1->val : 0;
		int y = (now2 != NULL) ? now2->val : 0;

		int sum = x + y + carry;
		carry = sum / 10;

		if(ans->val == -1)
			ans->val = sum % 10;
		else
		{
			ListNode *newNode = new ListNode(sum % 10);
			current->next = newNode;
			current = current->next;
		}

		now1 = (now1 != NULL) ? now1->next : 0;
		now2 = (now2 != NULL) ? now2->next : 0;
	}
	if (carry != 0)
	{
		ListNode *newNode = new ListNode(carry);
		current->next = newNode;
	}
	return ans;
}

void push_back(int x, ListNode *node)
{
	ListNode *newNode = new ListNode(x); // new memory

	if (node == 0)			// 若list為空, 令newNode為first
	{
		node = newNode;
		return;
	}

	ListNode *current = node;
	while (current->next)		// travarsal
	{
		current = current->next;
	}
	current->next = newNode;	// newNode接在list的尾端
}
void print_list(ListNode* node)
{
	ListNode *current = node;
	while (current)
	{
		cout << int(current->val) << " ";
		current = current->next;
	}
	cout << "\n";
}

int main()
{
	int len1 = 0, len2 = 0;
	vector<int> list1, list2;
	while (cin >> len1 >> len2)
	{
		list1.resize(len1);
		list2.resize(len2);
		for (int i = 0; i < len1; i++)
			cin >> list1[i];
		for (int i = 0; i < len2; i++)
			cin >> list2[i];

		Solution ans;
		ListNode *l1 = new ListNode(list1[0]);
		ListNode *l2 = new ListNode(list2[0]);
		for (int i = 1; i < list1.size(); i++)
			push_back(list1[i], l1);
		for (int i = 1; i < list2.size(); i++)
			push_back(list2[i], l2);
		print_list(ans.addTwoNumbers(l1, l2));
	}
	return 0;
}