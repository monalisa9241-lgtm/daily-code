//Given the head of a linked list, 
// remove the nth node from the end of the list and return its head.

#include <iostream>
#include <list>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (!head)
		{
			return head;
		}
		if (head->next == NULL && n == 1)
		{
			head = NULL;
			return head;
		}

		int nodeCount = 0;
		ListNode* curr = head;
		while (curr != nullptr)
		{
			nodeCount++;
			curr = curr->next;
		}
		if (n == nodeCount)
		{
			ListNode* newHead = head->next;
			delete head;
			return newHead;
		}
		curr = head;
		for (int i = 1; i < nodeCount - n; i++)
		{
			curr = curr->next;
		}
		ListNode* NodeToDel = curr->next;
		curr->next = curr->next->next;
		delete NodeToDel;

		return head;
	}

	//Remove the nth node from the end of the list 
	// in one pass using two pointers (fast and slow)
	ListNode* removeNthFromEndFastSlow(ListNode* head, int n) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* fast = dummy;
		ListNode* slow = dummy;
		for (int i = 0; i <= n; i++) {
			fast = fast->next;
		}	
		while (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* nodeToDelete = slow->next;
		slow->next = slow->next->next;
		delete nodeToDelete;
		ListNode* newHead = dummy->next;
		delete dummy;
		return newHead;
	}
};
