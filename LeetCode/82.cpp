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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* pos = head;
        ListNode* pre = NULL;
        while(pos != NULL){
            ListNode* to = pos -> next;
            bool flag = false;
            while(to != NULL && to -> val == pos -> val){
                to = to -> next;
                flag = true;
            }
            if(flag){
                if(pre != NULL){
                    pre -> next = to;
                }else{
                    head = to;
                }
            }else{
                pre = pos;
            }
            pos = to;
        }
        return head;
    }
};