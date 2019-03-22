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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m == n){
            return head;
        }
        ListNode *tail = head;
        ListNode *pre, *start, *tmp1, *tmp2;
        int cnt = 1;
        for(int i = 1; i < m; i++){
            pre = tail;
            tail = tail->next;
        }
        tmp1 = tail;
        tmp2 = tail->next;
        for(int i = m; i < n; i++){
            tail = tmp2;
            tmp2 = tail->next;
            tail->next = tmp1;
            tmp1 = tail;
        }
        if(m > 1){
            start = pre->next;
            pre->next = tail;
            start->next = tmp2;
        }
        else{
            start = head;
            start->next = tmp2;
            head = tail;
        }
        
        return head;
    }
};