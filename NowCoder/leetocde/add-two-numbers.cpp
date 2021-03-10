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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        ListNode *head = nullptr, *cur = nullptr;
        ListNode *head1 = l1, *head2 = l2;
        int remain = 0;
        while(head1 != nullptr && head2 != nullptr) {
            if(cur == nullptr) {
                head = cur = new ListNode(head1->val + head2->val + remain);
            }else {
                cur->next = new ListNode(head1->val + head2->val + remain);
                cur = cur->next;
            }
            if(cur->val >= 10) {
                remain = 1;
                cur->val -= 10;
            }else {
                remain = 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1 != nullptr) {
            cur->next = new ListNode(head1->val + remain);
            cur = cur->next;
            if(cur->val >= 10) {
                remain == 1;
                cur->val -= 10;
            }else {
                remain = 0;
            }
            head1 = head1->next;
        }
        while(head2 != nullptr) {
            cur->next = new ListNode(head2->val + remain);
            cur = cur->next;
            if(cur->val >= 10) {
                remain == 1;
                cur->val -= 10;
            }else {
                remain = 0;
            }
            head2 = head2->next;
        }
        if(remain == 1) {
            cur->next = new ListNode(1);
        }
        return head;
    }
};