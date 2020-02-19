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
    void reorderList(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        fast = reverseList(fast);
        head = mergeList(head, fast);
    }
    
    ListNode* mergeList(ListNode *head1, ListNode *head2) {
        if(head1 == nullptr) {
            return head2;
        }
        ListNode *cur1 = head1, *cur2 = head2, *nex1 = nullptr, *nex2 = nullptr;
        while(cur1 != nullptr && cur2 != nullptr) {
            nex1 = cur1->next;
            nex2 = cur2->next;
            cur1->next = cur2;
            cur2->next = nex1;
            cur1 = nex1;
            cur2 = nex2;
        }
        return head1;
    }
    
    ListNode* reverseList(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr, *cur = head, *nex = head->next;
        while(nex != nullptr) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;
        return cur;
    }
};