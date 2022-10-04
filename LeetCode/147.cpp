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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *pre = head, *cur = pre->next;
        while(cur != NULL){
            ListNode *pre_finder = NULL, *finder = head;
            while(finder->val < cur->val && finder != cur){
                pre_finder = finder;
                finder = finder->next;
            }
            if(pre_finder == NULL){
                pre->next = cur->next;
                cur->next = head;
                head = cur;
            }else if(finder == cur){
                pre = cur;
            }else{
                pre->next = cur->next;
                cur->next = finder;
                pre_finder->next = cur;
            }
            cur = pre->next;
        }
        return head;
    }
};