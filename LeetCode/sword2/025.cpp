/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *tail1;
        int jin = 0;
        while (cur1 != nullptr && cur2 != nullptr) {
            (cur1 -> val) += cur2 -> val + jin;
            jin = (cur1 -> val) / 10;
            (cur1 -> val) %= 10;
            if (cur1 -> next == nullptr) {
                tail1 = cur1;
            }
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        if (cur2 != nullptr) {
            tail1 -> next = cur2;
            cur1 = cur2;
        }
        while (cur1 != nullptr) {
            (cur1 -> val) += jin;
            jin = (cur1 -> val) / 10;
            (cur1 -> val) %= 10;
            if (cur1 -> next == nullptr) {
                tail1 = cur1;
            }
            cur1 = cur1 -> next;
        }
        if (jin > 0) {
            tail1 -> next = new ListNode(jin);
        }
        l1 = reverseLinkedList(l1);
        return l1;
    }

    ListNode* reverseLinkedList(ListNode *originalHead) {
        if (originalHead == nullptr || originalHead -> next == nullptr) {
            return originalHead;
        }
        ListNode *cur = originalHead;
        ListNode *nex = originalHead -> next;
        cur -> next = nullptr;
        while (nex != nullptr) {
            ListNode *pre = cur;
            cur = nex;
            nex = cur -> next;
            cur -> next = pre;
        }
        return cur;

    }
};