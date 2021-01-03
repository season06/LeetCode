#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (m == n)
		return head;

	vector<ListNode*> stack;
	ListNode* node = head;
	ListNode* reverse = NULL;

	for (int i = 1; i < m; i++)
	{
		reverse = node;
		node = node->next;
	}
	for (int i = m; i <= n; i++)
	{
		stack.push_back(node);
		node = node->next;
	}

	ListNode* last = stack[stack.size() - 1];
	if (m == 1) // 如果需反轉的在開頭, head 直接指向 stack 最後一個元素 : head -> last -> node(iter)
		head = last;
	else // 若需反轉的在中間, 則 node 的下一個點指向 stack 最後一個元素 : head -> (node -> reverse) -> last -> node(iter)
		reverse->next = last;
	while (!stack.empty())
	{
		last->next = stack[stack.size() - 1];
		last = stack[stack.size() - 1];
		stack.pop_back();
	}
	last->next = node;

	return head;
}

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> list{ 5, 4, 3, 2, 6 };
		int m = 1, n = 4;
		ListNode* a = new ListNode(list[0]);
		ListNode* b = new ListNode(list[1]);
		ListNode* c = new ListNode(list[2]);
		ListNode* d = new ListNode(list[3]);
		ListNode* e = new ListNode(list[4]);
		a->next = b;
		b->next = c;
		c->next = d;
		d->next = e;
		e->next = nullptr;
		ListNode* ans = reverseBetween(a, m, n);
		while (ans)
		{
			cout << ans->val << " ";
			ans = ans->next;
		}
		cout << "\n";

	}
}