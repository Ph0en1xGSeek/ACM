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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        int length = 0;
        ListNode *node = head;
        while (node != nullptr) {
            ++length;
            node = node -> next;
        }
        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *prev = dummyHead, *cur = prev -> next;
            while (cur != nullptr) {
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur -> next != nullptr; ++i) {
                    cur = cur -> next;
                }
                ListNode *head2 = cur -> next;
                cur -> next = nullptr;
                cur = head2;
                for (int i = 1; i < subLength && cur != nullptr && cur -> next != nullptr; ++i) {
                    cur = cur -> next;
                }
                ListNode *next = nullptr;
                if (cur != nullptr) {
                    next = cur -> next;
                    cur -> next = nullptr;
                }
                ListNode *merged = merge(head1, head2);
                prev -> next = merged;
                while (prev -> next != nullptr) {
                    prev = prev -> next;
                }
                cur = next;
            }
        }
        return dummyHead -> next;
    }

    ListNode* merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1 -> val < head2 -> val) {
                cur -> next = head1;
                head1 = head1 -> next;
            } else {
                cur -> next = head2;
                head2 = head2 -> next;
            }
            cur = cur -> next;
        }
        if (head1 != nullptr) {
            cur -> next = head1;
        } else if (head2 != nullptr) {
            cur -> next = head2;
        }
        return dummyHead -> next;
    }
};