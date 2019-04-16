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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* le = NULL;
        ListNode* tail = NULL;
        while(head != NULL && head->val >= x){
            if(le == NULL){
                le = tail = head;
            }else{
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
            tail->next = NULL;
        }
        if(head == NULL){
            return le;
        }
        ListNode* cur = head->next;
        ListNode* pre = head;
        
        while(cur != NULL){
            if(cur->val >= x){
                if(le == NULL){
                    le = tail = cur;
                }else{
                    tail->next = cur;
                    tail = tail->next;
                }
                pre->next = cur->next;
                cur = cur-> next;
                tail->next = NULL;
            }else{
                cur = cur->next;
                pre = pre->next;
            }
        }
        pre->next = le;
        return head;
    }
};