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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        ListNode *nex = fast->next;
        fast->next = NULL;
        slow->next = NULL;
        while(nex != NULL){
            ListNode *tmp = nex->next;
            nex->next = fast;
            fast = nex;
            nex = tmp;
        }
        slow = head;
        ListNode *slow_nex;
        ListNode *fast_nex;
        while(fast != NULL && slow != NULL){
            slow_nex = slow->next;
            fast_nex = fast->next;
            slow->next = fast;
            fast->next = slow_nex;
            fast = fast_nex;
            slow = slow_nex;
        }
    }
        
};