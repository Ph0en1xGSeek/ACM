/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head1 = l1;
		ListNode *head2 = l2;
		if(l1 == nullptr) {
			return l2;
		}else if(l2 == nullptr) {
			return l1;
		}
		ListNode *head = nullptr, *tail = nullptr;
		while(head1 != nullptr && head2 != nullptr) {
			if(head1->val < head2->val) {
				if(tail == nullptr) {
					head = tail = head1;
				}else {
					tail->next = head1;
					tail = head1;
				}
				head1 = head1->next;
				tail->next = nullptr;
			}else {
				if(tail == nullptr) {
					head = tail = head2;
				}else {
					tail->next  =  head2;
					tail = head2;
				}
				head2 = head2->next;
				tail->next = nullptr;
			}
		}
		if(head1 != nullptr) {
			tail->next = head1;
		}else if(head2 != nullptr) {
			tail->next = head2;
		}
		return head;
	}
};
