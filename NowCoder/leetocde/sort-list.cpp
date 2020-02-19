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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(fast);
        head = merge(head1, head2);
        return head;
    }
    
    ListNode* merge(ListNode *head1, ListNode *head2) {
        if(head1->val > head2->val) {
            swap(head1, head2);
        }
        ListNode *cur1 = head1, *cur2 = head2;
        ListNode *tmp;
        while(cur1->next != nullptr && cur2 != nullptr) {
            if(cur1->next->val > cur2->val) {
                tmp = cur2;
                cur2 = cur2->next;
                tmp->next = cur1->next;
                cur1->next = tmp;
            }
            cur1 = cur1->next;
        }
        if(cur2 != nullptr) {
            cur1->next = cur2;
        }
        return head1;
    }
};