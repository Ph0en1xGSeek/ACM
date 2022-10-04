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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        } 
        ListNode *nex = head -> next;
        head -> next = NULL;
        while (nex != NULL) {
            ListNode *tmp = nex -> next;
            nex -> next = head;
            head = nex;
            nex = tmp;
        }
        return head;
    }
};