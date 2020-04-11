#include<iostream>
using namespace std;

class LinkedList;

class ListNode {
public:
	ListNode() :val(0), next(0) {};
	ListNode(int x) :val(x), next(0) {};
	friend class LinkedList;
private:
	int val;
	ListNode *next;
};

class LinkedList {
public:
	LinkedList() : node(0) {};
	void print_list();
	void push_front(int x);
	void push_back(int x);
	void delete_node(int x);
	void clear();
	void reverse();
private:
	ListNode *node;
};

void LinkedList::print_list()
{
	if (node == NULL)
	{
		cout << "List is empty\n";
		return;
	}

	ListNode *current = node;
	while (current)
	{
		cout << current->val << " ";
		current = current->next;
	}
	cout << "\n";
}
void LinkedList::push_front(int x)
{
	ListNode *newNode = new ListNode(x);
	newNode->next = node;
	node = newNode;
}
void LinkedList::push_back(int x)
{
	ListNode *newNode = new ListNode(x); // new memory

	if (node == NULL)			// �Ylist����, �OnewNode��node
	{
		node = newNode;
		return;
	}

	ListNode *current = node;
	while (current->next)		// travarsal
	{
		current = current->next;
	}
	current->next = newNode;	// newNode���blist������
}
void LinkedList::delete_node(int x)
{
	ListNode *prev = NULL, *current = node;
	while (current != NULL && current->val != x)	// �p�G�䤣�� or ���x�h����loop
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		cout << "There is no " << x << " in list. \n";
	else if (current == node)	// �n�R����node�b�Ĥ@��
	{
		node = current->next;
		delete current;
		current = NULL;
	}
	else
	{
		prev->next = current->next;
		delete current;
		current = NULL;
	}
}
void LinkedList::clear()
{
	while (node != NULL)
	{
		ListNode *current = node;
		node = node->next;
		delete current;
		current = NULL;
	}
}
void LinkedList::reverse()
{
	if (node == NULL || node->next == NULL)
		return;

	// ��V
	ListNode *prev = NULL, *current = node, *follow = node->next;
	while (follow)				// prev    -> current -> follow     -> follow.next
	{							// current -> follow  -> follow.next
		current->next = prev;
		prev = current;
		current = follow;
		follow = follow->next;
	}
	current->next = prev;	// ���̫�@��node, �Ncurrent->next��V
	node = current;
}

int main()
{
	LinkedList list;
	list.print_list();    // empty

	int arr[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++)
		list.push_back(arr[i]);
	list.print_list();	// 1 2 3

	list.push_front(0);
	list.print_list();	// 0 1 2 3

	list.delete_node(3);
	list.print_list();	// 0 1 2

	list.reverse();
	list.print_list();	// 2 1 0

	list.clear();
	list.print_list();    // empty

	system("pause");
	return 0;
}