#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: 1->1->2
Output: 1->2

Input: 1->1->2->3->3
Output: 1->2->3
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* node = head;
	while (node && node->next)
	{
		ListNode* nextNode = node->next;
		if (node->val == nextNode->val)
			node->next = nextNode->next;
		else
			node = node->next;
	}
	return head;
}

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> l1{ 1, 1, 2, 3, 3 };
		ListNode* a = new ListNode(l1[0]);
		ListNode* b = new ListNode(l1[1]);
		ListNode* c = new ListNode(l1[2]);
		ListNode* d = new ListNode(l1[3]);
		ListNode* e = new ListNode(l1[4]);
		a->next = b;
		b->next = c;
		c->next = d;
		d->next = e;
		ListNode* ans = deleteDuplicates(a);
		while (ans)
		{
			cout << ans->val << " ";
			ans = ans->next;
		}
		cout << "\n";
	}
}