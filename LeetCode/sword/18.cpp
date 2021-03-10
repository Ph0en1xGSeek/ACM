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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr) {
            if(cur->val == val) {
                if(pre == nullptr) {
                    head = cur->next;
                    return head;
                }else {
                    pre->next = cur->next;
                    return head;
                }
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};