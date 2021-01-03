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
	// use two pointer, slow ���@�B, fast ����B, �Y fast �P slow �۹J�N�� cycle
	// �Y�̫ᨫ�� nullptr �h�L cycle
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

	// �Y��� pointer �۹J, �N�� node �� cycle ���_�I
	// �ɶ��@��, fast �t�� = 2 �� slow �t��, �Z�������i�o��
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