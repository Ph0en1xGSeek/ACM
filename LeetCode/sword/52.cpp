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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = 0, cnt2 = 0;
        ListNode *cur = headA;
        while(cur != nullptr) {
            ++cnt1;
            cur = cur->next;
        }
        cur = headB;
        while(cur != nullptr) {
            ++cnt2;
            cur = cur->next;
        }
        while(cnt1 > cnt2) {
            headA = headA->next;
            --cnt1;
        }
        while(cnt2 > cnt1) {
            headB = headB->next;
            --cnt2;
        }
        while(headA != nullptr && headB != nullptr && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};