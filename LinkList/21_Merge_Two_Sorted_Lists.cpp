#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// recursive
/*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}*/

// iterative
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode ans;
	ListNode* node = &ans;
	while (l1 || l2)
	{
		if (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				node->next = l1;
				node = node->next;
				l1 = l1->next;
			}
			else
			{
				node->next = l2;
				node = node->next;
				l2 = l2->next;
			}
		}
		else if (l1)
		{
			node->next = l1;
			node = node->next;
			l1 = l1->next;
		}
		else if (l2)
		{
			node->next = l2;
			node = node->next;
			l2 = l2->next;
		}
	}
	return ans.next;
}

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> l1{ 1, 2, 4 }, l2 = { 1, 3, 4 };
		ListNode* a = new ListNode(l1[0]);
		ListNode* b = new ListNode(l1[1]);
		ListNode* c = new ListNode(l1[2]);
		a->next = b;
		b->next = c;
		ListNode* x = new ListNode(l2[0]);
		ListNode* y = new ListNode(l2[1]);
		ListNode* z = new ListNode(l2[2]);
		x->next = y;
		y->next = z;
		ListNode* ans = mergeTwoLists(a, x);
		while (ans)
		{
			cout << ans->val << " ";
			ans = ans->next;
		}
		cout << "\n";

	}
}