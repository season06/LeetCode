#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Input: 1->1->1->2->3
Output: 2->3
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
	ListNode* newHead = new ListNode(); // use a new ListNode to store no duplicate node
	ListNode* node = head;
	ListNode* newNode = newHead;
	while (node)
	{
		bool duplicate = false;
		while (node->next && node->val == node->next->val)
		{
			node = node->next;
			duplicate = true;
		}
		if (!duplicate)
		{
			newNode->next = node;
			newNode = newNode->next;
		}
		node = node->next;
	}
	newNode->next = nullptr;
	return newHead->next;
}

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> l1{ 1, 1, 2, 3, 4, 4 };
		ListNode* a = new ListNode(l1[0]);
		ListNode* b = new ListNode(l1[1]);
		ListNode* c = new ListNode(l1[2]);
		ListNode* d = new ListNode(l1[3]);
		ListNode* e = new ListNode(l1[4]);
		ListNode* f = new ListNode(l1[5]);
		a->next = b;
		b->next = c;
		c->next = d;
		d->next = e;
		e->next = f;
		ListNode* ans = deleteDuplicates(a);
		while (ans)
		{
			cout << ans->val << " ";
			ans = ans->next;
		}
		cout << "\n";
	}
}