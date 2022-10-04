/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        for (int i = 0; i < n; ++i) {
            tmp = tmp -> next;
        }
        ListNode *tmp2 = head;
        ListNode *pre = nullptr;
        while(tmp != nullptr) {
            tmp = tmp -> next;
            pre = tmp2;
            tmp2 = tmp2 -> next;
        }
        if (tmp2 -> next == nullptr) {
            if (pre == nullptr) {
                return nullptr;
            } else {
                pre -> next = nullptr;
                return head;
            }
        } else if (tmp2 == head) {
            head = head -> next;
            tmp2 -> next = nullptr;
            return head;
        } else {
            pre -> next = tmp2 -> next;
            tmp2 -> next = nullptr;
            return head;
        }
    }
};