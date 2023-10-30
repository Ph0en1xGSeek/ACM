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
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *tmpA = headA, *tmpB = headB;
        while (tmpA != tmpB && (tmpA != nullptr || tmpB != nullptr)) {
            if (tmpA == nullptr) {
                tmpA = headB;
            } else if (tmpB == nullptr) {
                tmpB = headA;
            } else {
                tmpA = tmpA -> next;
                tmpB = tmpB -> next;
            }
        }
        return tmpA;
    }
};