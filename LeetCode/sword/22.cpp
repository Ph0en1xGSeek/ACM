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
    ListNode* getKthFromEnd(ListNode* head, int k) {
	ListNode *cur = head;
	int i = 0;
	while(cur != nullptr && i < k) {
		++i;
		cur = cur->next;
	}
	if(i < k) {
		return nullptr;
	}
	ListNode *ans = head;
	while(cur != nullptr) {
		ans = ans->next;
		cur = cur->next;
	}
	return ans;
    }
};
