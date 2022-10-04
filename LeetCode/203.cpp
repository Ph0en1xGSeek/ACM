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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr){
            if(cur->val == val){
                if(cur == head){
                    head = head->next;
                }else{
                    pre->next = cur->next;
                }
            }else{
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};