#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Input: head = [3,2,0,-4], pos = 1
Output: true

Input: head = [1], pos = -1
Output: false
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return nullptr;

	// Floyd Cycle Detection Algorithm
	// use two pointer, slow 走一步, fast 走兩步, 若 fast 與 slow 相遇代表有 cycle
	// 若最後走到 nullptr 則無 cycle
	ListNode* slow = head;
	ListNode* fast = head;
	while (1)
	{
		if (fast == NULL || fast->next == NULL)
			return nullptr;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	// 若兩個 pointer 相遇, 代表此 node 為 cycle 的起點
	// 時間一樣, fast 速度 = 2 倍 slow 速度, 距離公式可得證
	// 2 * dist(slow) = dist(fast)
	fast = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> l1{ 0, 1, 2, 3 };
		int pos = 1;
		ListNode* a = new ListNode(l1[0]);
		ListNode* b = new ListNode(l1[1]);
		ListNode* c = new ListNode(l1[2]);
		ListNode* d = new ListNode(l1[3]);
		a->next = b;
		b->next = c;
		c->next = d;
		d->next = b;
		ListNode* ans = detectCycle(a);
		while (ans)
		{
			cout << ans->val << " ";
			ans = ans->next;
		}
		cout << "\n";
	}
}